import os
import re as rere
import numpy as np
from scipy import io as sio
from libtiff import TIFF


def generate_sphere_d(numcols):
    order = numcols * 2 + 1
    order1 = numcols * 2 + 1
    number = range(0, order * order, 1)
    number = np.flipud(number)
    core1 = np.zeros([order, order], dtype=np.int16)
    numberindex = 0
    for ii in range(numcols):
        core1[ii, ii:order] = number[numberindex:numberindex + order1]
        core1[ii + 1:order - 1, order - 1] = number[numberindex + order1:numberindex + 2 * order1 - 2]
        core1[order - 1, ii:order] = np.flipud(number[numberindex + 2 * order1 - 2:numberindex + 3 * order1 - 2])
        core1[ii + 1:order - 1, ii] = np.flipud(number[numberindex + 3 * order1 - 2:numberindex + 4 * order1 - 4])
        numberindex = numberindex + 4 * order1 - 4
        order = order - 1
        order1 = order1 - 2

    # core1 = np.fliplr(core1)
    core1 = np.rot90(core1)
    return core1


def load_img(file):
    if file.endswith('.mat'):
        filecont = sio.loadmat(file)
        img = filecont['img']
        for z in range(img.shape[-1]):  # Flip the image upside down
            img[:, :, z] = np.flipud(img[:, :, z])
        img = np.swapaxes(img, 0, 1)
    elif file.endswith('.tif'):
        img = loadtiff3d(file)
    elif file.endswith('.nii') or file.endswith('.nii.gz'):
        import nibabel as nib
        img = nib.load(file)
        img = img.get_data()
    else:
        raise IOError(
            "The extension of " + file + 'is not supported. File extension supported are: *.tif, *.mat, *.nii')

    return img


def loadtiff3d(filepath):
    """Load a tiff file into 3D numpy array"""
    from libtiff import TIFF
    tiff = TIFF.open(filepath, mode='r')
    stack = []
    for sample in tiff.iter_images():
        stack.append(sample)
        # stack.append(np.rot90(np.fliplr(np.flipud(sample))))
    out = np.dstack(stack)
    tiff.close()

    return out


def loadtiff3d_noflip(filepath):
    """Load a tiff file into 3D numpy array"""
    # from libtiff import TIFF
    tiff = TIFF.open(filepath, mode='r')
    stack = []
    for sample in tiff.iter_images():
        # stack.append(np.rot90(np.fliplr(np.flipud(sample))))
        stack.append(sample)
    out = np.dstack(stack)
    tiff.close()

    return out


def read3dtiff(filepath):
    from libtiff import TIFF
    tiff = TIFF.open(filepath, mode='r')
    stack = []
    for sample in tiff.iter_images():
        stack.append(sample)
    out = np.array(stack)
    tiff.close()

    return out


def read3d_flipud(filepath):
    from libtiff import TIFF
    tiff = TIFF.open(filepath, mode='r')
    stack = []
    for sample in tiff.iter_images():
        stack.append(np.flipud(sample))
    out = np.array(stack)
    tiff.close()

    return out


def writetiff3d_ori(filepath, block):
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    # block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[2]):
        # tiff.write_image(block[:, :, z], compression=None)
        tiff.write_image(block[:, :, z], compression='lzw')
    tiff.close()


def writetiff3d_ori_no_compress(filepath, block):
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    # block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[2]):
        tiff.write_image(block[:, :, z], compression=None)
        # tiff.write_image(block[:, :, z], compression='lzw')
    tiff.close()


def writetiff3d(filepath, block):
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[2]):
        tiff.write_image(np.flipud(block[:, :, z]), compression=None)
    tiff.close()


def writetiff3dtest(filepath, block):
    from libtiff import TIFF
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[2]):
        tiff.write_image((block[:, :, z]), compression=None)
    tiff.close()


def write3dimg(filepath, block):
    from libtiff import TIFF
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    # block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[0]):
        tiff.write_image(np.flipud(block[z, :, :]), compression=None)  # np.flipud
    tiff.close()


def write3dimg_noflip(filepath, block):
    from libtiff import TIFF
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    # block = np.swapaxes(block, 0, 1)

    for z in range(block.shape[0]):
        # tiff.write_image(block[z, :, :], compression=None) #np.flipud
        tiff.write_image(block[z, :, :], compression='lzw')
    tiff.close()


def writetiff2d(filepath, block):
    try:
        os.remove(filepath)
    except OSError:
        pass

    tiff = TIFF.open(filepath, mode='w')
    # block = np.swapaxes(block, 0, 1)

    #    for z in range(block.shape[2]):
    tiff.write_image((block[:, :]), compression=None)
    # tiff.write_image((block[:, :]), compression='lzw')
    tiff.close()


def loadswc(filepath):
    '''
    Load swc file as a N X 7 numpy array
    '''
    swc = []
    with open(filepath) as f:
        lines = f.read().split("\n")
        for l in lines:
            if not l.startswith('#'):
                cells = l.split(' ')
                if len(cells) != 7:
                    for kk in range(len(cells) - 1, -1, -1):
                        if cells[kk] == '':
                            cells.pop(kk)
                if len(cells) == 7:
                    cells = [float(c) for c in cells]
                    # cells[2:5] = [c-1 for c in cells[2:5]]
                    swc.append(cells)
    return np.array(swc)


def loadmarker(filepath):
    '''
    Load swc file as a N X 7 numpy array
    '''
    marker = []
    with open(filepath) as f:
        lines = f.read().split("\n")
        for l in lines:
            if not l.startswith('#'):
                cells = rere.split(', ', l)
                if len(cells) == 8:
                    cells = [float(c) for c in cells[0:3]]
                    marker.append(cells)
    return np.array(marker)


def saveswc(filepath, swc, position=None):
    if swc.shape[1] > 7:
        swc = swc[:, :7]
    if position is not None:
        swc[:, 2] = swc[:, 2] + int(position[0])
        swc[:, 3] = swc[:, 3] + int(position[1])
        swc[:, 4] = swc[:, 4] + int(position[2])
    with open(filepath, 'w') as f:
        for i in range(swc.shape[0]):
            print('%d %d %.3f %.3f %.3f %.3f %d' %
                  tuple(swc[i, :].tolist()), file=f)


def crop(img, thr):
    """Crop a 3D block with value > thr"""
    ind = np.argwhere(img > thr)
    x = ind[:, 0]
    y = ind[:, 1]
    z = ind[:, 2]
    xmin = max(x.min() - 10, 0)
    xmax = min(x.max() + 10, img.shape[0])
    ymin = max(y.min() - 10, 1)
    ymax = min(y.max() + 10, img.shape[1])
    zmin = max(z.min() - 10, 2)
    zmax = min(z.max() + 10, img.shape[2])

    return img[xmin:xmax, ymin:ymax, zmin:zmax], np.array(
        [[xmin, xmax], [ymin, ymax], [zmin, zmax]])

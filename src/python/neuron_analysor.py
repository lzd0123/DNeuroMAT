import os
import yaml
import torch


class NeuronAnalysor:
    def __init__(self, image_path: str = "None", output_path: str = "None"):
        assert image_path != "None" and output_path != "None"
        self.image_path = image_path
        self.output_path = output_path
        self.image_list = []
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    def find_image(self) -> None:
        """
            This function is used to find all images whose name ends with .tif

            return:
                A list contains .tif images.
            """
        if self.image_path.endswith(".tif"):
            self.image_list.append(self.image_path)
        elif os.path.isdir(self.image_path):
            file_names = os.listdir(self.image_path)
            for file_name in file_names:
                if file_name.endswith(".tif"):
                    self.image_list.append(os.path.join(self.image_path, file_name))

    def read_parameter(self, parameter_path: str) -> dict:
        """
        This function is used to read parameters from a .yaml file.

        arg:
            parameter_path: the path of .yaml file.

        return:
            A dictionary contains parameters read from .yaml.
        """
        if not os.path.exists(parameter_path) or not parameter_path.endswith(".yaml"):
            raise RuntimeError("failed to read parameters, no such a file or the file doesn't end with .yaml.")
        with open(parameter_path) as f:
            parameter_dict = yaml.load(f, Loader=yaml.Loader)
        return parameter_dict

    def run(self) -> None:
        """
        This function is used to process images iteratively.
        """
        self.find_image()
        for image_name in self.image_list:
            self.process(image_name)

    def process(self, image_name: str):
        """
        This function must be overloaded  by users.
        """
        pass
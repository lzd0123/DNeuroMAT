#include "surf_objs.h"

// double Node::getGeometryDistanceBetween(const Node* other, const Image4DSimple* image)
// {
    
// }
NodeList readSWCFile(QString filePath)
{
    NodeList neuronTree;
    ifstream ifs(filePath.toStdString());
    if (ifs.fail()) return neuronTree;
    map<int, Node*> nodeMap;
	map<Node*, int> parid_map;
    
    for (;ifs.good(); ifs.ignore(1024,'\n'))
	{
		if(ifs.peek() == '#' || ifs.eof()) continue;
		int id = -1; ifs >> id;
		if(id == -1) break;
		Node* marker = new Node;
        nodeMap[id] = marker;
		ifs >> marker->type;
		ifs >> marker->x;
		ifs >> marker->y;
		ifs >> marker->z;
		ifs >> marker->radius;
		int par_id = -1; ifs >> par_id;
		parid_map[marker] = par_id;
		neuronTree.push_back(marker);
	}
	ifs.close();
    
    for (Node* n: neuronTree)
    {
        int parid = parid_map[n];
        if (parid == -1) continue;
        n->parent = nodeMap[parid];
        n->parent->children.push_back(n);
    }
    return neuronTree;
}

bool saveSWCFile(QString filePath, NodeList& neuronTree)
{
    ofstream ofs(filePath.toStdString(), ios::binary);
    if (ofs.fail()) {std::cout<<"[Error] Open save file failed."<<std::endl;return false;}
    V3DLONG nums = 0;
    map<Node*, V3DLONG> ind;
    for (Node* node: neuronTree) ind.insert(pair<Node*, V3DLONG>(node, ++nums));
    ofs<<"# name "<<qPrintable(filePath)<<std::endl;
    ofs<<"# comment "<<std::endl;
    ofs<<"# n, type, x, y, z, radius, parent"<<std::endl;
    nums = 0;
    for (Node* node: neuronTree)
    {
        int parent_id = (node->parent)? ind[node->parent]: -1;
        ofs<<++nums<<" "<<node->type<<" "<<node->x<<" "<<node->y<<" "<<node->z<<" "<<node->radius<<" "<<parent_id<<std::endl;
    }
    std::cout<<"[Info] Marker num = "<<nums<<", save swc file to "<<qPrintable(filePath)<<std::endl;
    ofs.close();
    return true;
}

MarkerList readMarkerFile(QString filePath)
{
    MarkerList markers;
    ifstream ifs(filePath.toStdString());
    if (ifs.fail()) return markers;
    for (;ifs.good(); ifs.ignore(1024,'\n'))
    {
        if (ifs.peek() == '#' || ifs.eof()) continue;
        markers.push_back(Marker());
        Marker* m = &markers.back();
        ifs >> m->x; ifs.ignore(10, ','); 
        ifs >> m->y; ifs.ignore(10, ',');
        ifs >> m->z; ifs.ignore(10, ',');
        ifs >> m->radius; ifs.ignore(10, ',');
        ifs >> m->shape; ifs.ignore(10, ',');
        ifs >> m->name; ifs.ignore(10, ',');
        ifs >> m->comment; ifs.ignore(10, ',');
        ifs >> m->colorRed; ifs.ignore(10, ',');
        ifs >> m->colorGreen; ifs.ignore(10, ',');
        ifs >> m->colorBlue;
    }
    ifs.close();
    return markers;
}

bool saveMarkerFile(QString filePath, MarkerList& markers)
{
    ofstream ofs(filePath.toStdString(), ios::binary);
    if (ofs.fail()) return false;
    ofs << "##x,y,z,radius,shape,name,comment, color_r,color_g,color_b" << std::endl;
    for (Marker& m: markers)
    {
        ofs << m.x << "," << m.y << "," << m.z << "," << m.radius << "," << m.shape << "," << m.name << "," << m.comment << "," << m.colorRed << "," << m.colorGreen << "," << m.colorBlue << std::endl;
    }
    ofs.close();
    return true;
}
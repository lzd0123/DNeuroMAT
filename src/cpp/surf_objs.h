#ifndef __SURF_OBJS_H__
#define __SURF_OBJS_H__

#include <vector>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <map>
#include <QtCore>
#include <v3d_interface.h>
using namespace std;

struct Node
{
    int type;
    double x;
    double y;
    double z;
    double radius;
    Node* parent;
    QList<Node*> children;
    QList<Node*>* pBelongToNodeList;
    Node(): type(0), x(0), y(0), z(0), radius(0), parent(nullptr), pBelongToNodeList(nullptr){}
    Node(int x_, int y_, int z_): Node() {x = x_, y = y_, z = z_;}
    Node(int type_, int x_, int y_, int z_, int radius_, Node* parent_, QList<Node*>& children_, QList<Node*>* blockPointer_):
        type(type_), x(x_), y(y_), z(z_), radius(radius_), parent(parent_), children(children_), pBelongToNodeList(blockPointer_){}
    Node(const Node& other): type(other.type), x(other.x), y(other.y), z(other.z), parent(other.parent), children(other.children), pBelongToNodeList(other.pBelongToNodeList){}
    Node& operator=(const Node& other)
    {
        this->type = other.type;
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->parent = other.parent;
        this->children = other.children;
        this->pBelongToNodeList = other.pBelongToNodeList;
        return *this;
    }
    ~Node()
    {
        if (parent) parent->children.removeOne(this);
        for (Node* child: children) child->parent = nullptr;
        if (pBelongToNodeList) pBelongToNodeList->removeOne(this);
    }
    double getDistanceBetween(const Node* other) {return sqrt(pow(this->x - other->x, 2) + pow(this->y - other->y, 2) + pow(this->z - other->z, 2));}
    double getGeometryDistanceBetween(const Node* other, const Image4DSimple* image);
};
typedef QList<Node*> NodeList;

struct BlockSimple
{
    bool isStartBlock;
    V3DLONG originX, originY, originZ, blockSizeX, blockSizeY, blockSizeZ;
    NodeList* pBlockNodeList;
    BlockSimple():isStartBlock(false), originX(-1), originY(-1), originZ(-1), blockSizeX(-1), blockSizeY(-1), blockSizeZ(-1), pBlockNodeList(nullptr) {};
    BlockSimple(const BlockSimple&);
    BlockSimple& operator=(const BlockSimple&);
    ~BlockSimple()
    {
        if (pBlockNodeList != nullptr)
        {
            while (pBlockNodeList->size()) delete pBlockNodeList->front();
            delete pBlockNodeList;
        }
    }
};
typedef QList<BlockSimple*> BlockSimpleList;

struct Marker
{
    double x, y, z, radius;
    int shape, colorRed, colorGreen, colorBlue;
    string name, comment;
    Marker():x(0), y(0), z(0), radius(0), shape(1), colorRed(255), colorGreen(0), colorBlue(0), name(""), comment(""){}
    Marker(const Marker& other):x(other.x), y(other.y), z(other.z), radius(other.radius), shape(other.shape), colorRed(other.colorRed), colorGreen(other.colorGreen), colorBlue(other.colorBlue), name(other.name), comment(other.comment){}
    Marker& operator=(const Marker& other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->radius = other.radius;
        this->shape = other.shape;
        this->colorRed = other.colorRed;
        this->colorGreen = other.colorGreen;
        this->colorBlue = other.colorBlue;
        this->name = other.name;
        this->comment = other.comment;
    }
    double getDistanceBetween(const Marker* other) {return sqrt(pow(this->x - other->x, 2) + pow(this->y - other->y, 2) + pow(this->z - other->z, 2));}
};
typedef QList<Marker> MarkerList;

NodeList readSWCFile(QString filePath);
bool saveSWCFile(QString filePath, NodeList& neuronTree);
MarkerList readMarkerFile(QString filePath);
bool saveMarkerFile(QString filePath, MarkerList& markers);

struct Coordinate
{
	double x, y, z;
	Coordinate() {x = y = z = -1;}
	Coordinate(double xx, double yy, double zz) {x = xx, y = yy, z = zz;}
	bool operator==(const Coordinate& other) const
	{
		if (this->x != other.x) return false;
		if (this->y != other.y) return false;
		if (this->z != other.z) return false;
		return true;
	}
	bool operator!=(const Coordinate& other) const
	{
		return !(*this == other);
	}
	bool operator<(const Coordinate& other) const
	{
		return *this != other;
	}
};

struct Vertex
{
	double x, y, z;
	QList<pair<Vertex*, double>> adjacent;
    Vertex(): x(-1), y(-1), z(-1) {adjacent.clear();}
	Vertex(double xx, double yy, double zz):x(xx), y(yy), z(zz) {adjacent.clear();}
    double getDistanceBetween(const Vertex* other) {return sqrt(pow(this->x - other->x, 2) + pow(this->y - other->y, 2) + pow(this->z - other->z, 2));}
};
typedef pair<Vertex*, double> Adjacent;
typedef QList<Vertex*> VertexList;
#endif//__SURF_OBJS_H__
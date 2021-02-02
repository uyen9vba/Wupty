
#include <vector>

struct Vertex {
	int index;
	bool ocean;
	bool water;
	bool coast;
	bool border;
	float altitude;
	float moisture;

	std::vector<Polygon> polygons;
	std::vector<Edge> protrudes;
	std::vector<Vertex> adjacents;

	Vertex downslope;
	Vertex watershed;
	Point point;
}


#include <vector>

struct Vertex {
	bool ocean;
	bool water;
	bool coast;
	bool border;
	bool river;
	float elevation;
	float moisture;

	std::vector<Polygon> polygons;
	std::vector<Edge> protrudes;
	std::vector<Vertex> adjacents;

	Vertex downslope;
	Vertex watershed;
}

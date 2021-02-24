
#include <vector>

struct Vertex {
	int index; // initialized
	bool ocean; // initialized
	bool coast;
	bool border; // initialized
	float elevation; // initialized
	float moisture;

	std::vector<Polygon> polygons;
	std::vector<Edge> protrudes;
	std::vector<Vertex> adjacents;

	Vertex* downslope; // initialized
	Vertex* watershed;
	Point point; // initialized
}

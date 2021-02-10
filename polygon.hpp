
#include <vector>

struct Polygon {
	bool ocean;
	bool coast;
	bool border;
	float elevation;
	float moisture;
	std::vector<Polygon> adjacents;
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;

	Biome biome;
	Point point;
}

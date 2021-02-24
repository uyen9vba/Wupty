
#include <vector>

struct Polygon {
	bool ocean; // initialized
	bool coast;
	bool border; // initialized
	float elevation; // initialized
	float moisture;
	std::vector<Polygon> adjacents;
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;

	Biome biome;
	Point point;
}

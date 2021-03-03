
#include <vector>

struct Site {
	bool ocean; // initialized
	bool coast;
	bool border; // initialized
	float elevation; // initialized
	float moisture;
	std::vector<Site> adjacents;
	std::vector<HalfEdge> edges;
	std::vector<Vertex> vertices;

	Biome biome;
	Point point; // initialized
}

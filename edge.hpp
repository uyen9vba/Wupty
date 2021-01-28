
#include <vector>

struct Edge {
	int river;

	Delaunay delaunay; // Delaunay edge
	Voronoi voronoi; // Voronoi edge
	Point midpoint;
}

struct Delaunay {
	Polygon x;
	Polygon y;
}

struct Voronoi {
	Vertex x;
	Vertex y;
}

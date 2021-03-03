
#include <vector>
#include <string>

#include <include/bitmap/bitmap_image.hpp>

class Map {
	public:
		Map(int size, float altitude, float elevation, float noise,
			float erosion, float lakes, float structures,
			float habitation, Climate climate);

		void create(int points);
		void assign_attributes();

		void build_sites();
		void build_vertices();
		void build_halfedges();
		
		void lloyd_relaxation();

		void save_image();
	private:
		int number_of_points; // Used for Voronoi diagram
		int size; // Size in pixels
		float altitude; // 0 to 1.0 on sea and land features
		float elevation; // 0 to 1.0 on how much flat and steep terrain features
		float noise; // 0 to 1.0 based on amount of noise
		float erosion; // 0 to 1.0 based on amount of erosion
		float lakes; // 0 to 1.0 based on amount of lakes
		float structures; // 0 to 1.0 based on amount of structures
		float habitation; // 0 to 1.0 based on habitation concentration
		std::vector<Point> points;
		std::vector<Vertex> vertices;
		std::vector<Site> sites;
		std::vector<HalfEdge> halfedges;

		Climate climate; // Base climate of the whole map
		bitmap_image bitmap_image;
		VoronoiDiagram voronoi_diagram;
}

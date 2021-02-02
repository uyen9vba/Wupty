
#include <vector>
#include <string>

#include <include/bitmap/bitmap_image.hpp>

class Map {
	public:
		Map(int size, float altitude, float elevation, float noise, float erosion, float lakes, float structures, float habitation, Climate climate);

		void create(int points);
		void assign_elevations(int points);
		void build_graph(std::vector<Vector2> points, VoronoiDiagram voronoi_diagram);
		void lloyd_relaxation();

		void save_image();

		static std::string get_biome(Polygon);
		void set_biomes();

		Edge lookup_edge(Polygon, Polygon);
		Edge lookup_edge(Vertex, Vertex);
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
		std::vector<Polygon> polygons;
		std::vector<Edge> edges;

		Climate climate; // Base climate of the whole map
		bitmap_image bitmap_image;
		VoronoiDiagram voronoi_diagram;
}

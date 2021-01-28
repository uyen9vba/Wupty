
#include <vector>
#include <string>

class Map {
	public:
		explicit Map(int size, float altitude, float elevation, float noise, float erosion, float lakes, float structures, float habitation, Climate climate);

		static std::string get_biome(Polygon);
		void set_biomes();

		Edge lookup_edge(Polygon, Polygon);
		Edge lookup_edge(Vertex, Vertex);
	private:
		int points;
		int size; // Size in pixels
		float lake_threshold;
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
}

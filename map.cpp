
#include <vector>
#include <random>
#include <string>

#include <include/FortuneAlgorithm/src/main.cpp>
#include <include/FortuneAlgorithm/src/VoronoiDiagram.h>

class Map {

	Map(int size, float altitude, float elevation, float noise, float erosion, float lakes, float structures, float habitation, Climate climate) :

		size(size),
		altitude(altitude),
		elevation(elevation),
		noise(noise),
		erosion(erosion),
		lakes(lakes),
		structures(structures),
		habitation(habitation),
		climate(climate),
		bitmap_image(size, size)
		{}
	
	void create(int number_of_points) {
		voronoi_diagram = generateRandomDiagram(number_of_points);

		// Build graph out of points and voronoidiagram
		build_graph(points, voronoi_diagram);

		// Assign elevations data
		assign_elevations()
	}
	
	/*
	 * Assign elevation to vertices
	 */
	void assign_elevations(int points) {
			
	}

	/*
	 * Initialize custom data 
	 */
	void build_graph(std::vector<Vector2> points, VoronoiDiagram voronoi_diagram) {
		std::random_device random_device;
		std::mt19937 mt19937(random_device());
		std::uniform_real_distribution<> uniform_real_distribution(0.0, 1.0);

		for (int a = 0; a < points.size(); a++) {
			float polygon_altitude = uniform_real_distribution(mt19937);
			Polygon polygon;
			
			if (polygon_altitude <= altitude) {
				polygon.ocean = true;
			} else {
				polygon.ocean = false;
			}

			polygon.index = voronoi_diagram.mSites[a].index;
			polygons.push_back(polygon);
		}
	}	
	
	void lloyd_relaxation() {
		for (auto& a : voronoi_diagram.mFaces) {
			if (a.	
	/*
	static std::vector<Vector2> generate_points(int size) {
		std::vector<Vector2> points;

		std::random_device random_device;
		std::mt19937 mt19937(random_device());
		std::uniform_real_distribution<float> uniform_real_distribution(0.0, 1.0);

		for(a = 0; a < points; a++) {
			Vector2 vector2 (uniform_real_distribution(mt19937),
					uniform_real_distribution(mt19937));

			points.push_back(point);
		}

		return points;
	}
	*/

}

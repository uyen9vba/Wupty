
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
	void assign_attributes() {
		
	}

	/*
	 * Initialize custom data 
	 */
	void build_graph(std::vector<Vector2> points, VoronoiDiagram voronoi_diagram) {
		std::random_device random_device;
		std::mt19937 mt19937(random_device());
		std::uniform_real_distribution<> uniform_real_distribution(0.0, 1.0);

		// Polygons
		for (auto& a : voronoi_diagram.mSites) {
			float elevation = uniform_real_distribution(mt19937);
			Polygon polygon{elevation = elevation, index = a.index};
			
			if (elevation <= altitude) {
				polygon.ocean = true;
			} else {
				polygon.ocean = false;
			}
			
			polygons.push_back(polygon);
		}
		
		// Vertices
		for (auto& a : voronoi_diagram.mVertices) {
			Vertex vertex;

			if (a.point.x == 0 || a.point.y == 0 || a.point.x == 1.0 || a.point.y == 1.0) {
				vertex.border = true;
			} else {
				vertex.border = false;
			}
			
			vertex.point.x = a.point.x;
			vertex.point.y = a.point.y;
			vertices.push(vertex);
		}

		// Edges
		for (auto& a : voronoi_diagram.mHalfEdges) {
			Point midpoint((a->origin.point.x + a->destination.point.x) / 2),
			      ((a->origin.point.y + a->destination.point.y) /2);

			Edge edge{midpoint = midpoint};
		}
				
	}	
	
	void lloyd_relaxation() {
		for (auto& a : voronoi_diagram.mFaces) {
			if (a.	

}

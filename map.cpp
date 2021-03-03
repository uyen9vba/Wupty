
#include <vector>
#include <random>
#include <string>
#include <iostream>

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
		std::cout << "Generating voronoi diagram...\n";
		voronoi_diagram = generateRandomDiagram(number_of_points);

		// Build graph out of points and voronoi diagram
		std::cout << "Building graphs...\n";
		build_sites();
		build_vertices();
		build_halfedges();


	}
	
	void build_sites() {
		std::random_device random_device;
		std::mt19937 mt19937(random_device());
		std::uniform_real_distribution<> uniform_real_distribution(0.0, 1.0);

		for (auto& a : voronoi_diagram.mSites) {
			float elevation = uniform_real_distribution(mt19937);
			Point point{x = a.x, y = a.y};
			Site site{elevation = elevation, index = a.index, point = point};

			if (elevation <= altitude) {
				site.ocean = true;
			} else {
				site.ocean = false;
			}
			
			sites.push_back(site);
		}
	}
		
	void build_vertices() {
		std::random_device random_device;
		std::mt19937 mt19937(random_device());
		std::uniform_real_distribution<> uniform_real_distribution(0.0, 1.0);

		for (auto& a : voronoi_diagram.mVertices) {
			float elevation = uniform_real_distribution(mt19937);
			Vertex vertex{elevation = elevation};

			if (a.point.x == 0 || a.point.y == 0 || a.point.x == 1.0 || a.point.y == 1.0) {
				vertex.border = true;
			} else {
				vertex.border = false;
			}

			if (elevation <= altitude) {
				vertex.ocean = true;
			} else {
				vertex.ocean = false;
			}

			vertex.index = a.it;
			vertex.point.x = a.point.x;
			vertex.point.y = a.point.y;
			vertices.push_back(vertex);
		}

	}

	void build_halfedges() {
		for (auto& a : voronoi_diagram.mHalfEdges) {
			Point midpoint((a->origin.point.x + a->destination.point.x) / 2),
			      ((a->origin.point.y + a->destination.point.y) /2);

			HalfEdge halfedge{midpoint = midpoint, site = a->incidentFace->site};

			if (vertices[a.origin->it].elevation =< vertices[a.destination->it].elevation) {
				vertices[a.origin->it].downslope = *vertices[a.destination->it];
			} else {
				vertices[a.origin->it].downslope = nullptr;
			}

			halfedges.push_back(halfedge);
	}
	
	void lloyd_relaxation() {
		for (auto& a : voronoi_diagram.mFaces)

	

}

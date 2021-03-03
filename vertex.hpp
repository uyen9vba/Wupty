
#include <vector>

struct Vertex {
	int index; // initialized
	bool ocean; // initialized
	bool coast;
	bool border; // initialized
	float elevation; // initialized
	float moisture;

	Vertex* downslope; // initialized
	Vertex* watershed;
	Point point; // initialized
}

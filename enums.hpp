
#include <string>

enum class Climate {
	tropical,
	dry,
	temperate,
	continental,
	polar
}

enum class Biome {
	aqua,
	grassland,
	forest,
	desert,
	tundra,
}

enum class Colors : std::string {
	aqua = "0x44447a",
	beach = "0x33335a",
	ice = "0x99ffff",
	tarmac = "0x442211",
	snow = "0xffffff",
	tundra = "0xbbbbaa",
	taiga = "0x99aa77",
	grass = "0x88aa55",
	dirt = "",
	rock = "",
	forest = "",
	gravel = ""
}

//============================================================================
// Name        : wordlist.cpp
// Author      : Petr Stepanov
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>

// https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int main() {
	const char* car_makes [] = {
							"Audi",
							"Alfa Romeo",
							"Acura",
							"Aston Martin",
							"BMW",
							"Bentley",
							"Buick",
							"Cadillac",
							"Chrysler",
							"Chevrolet",
							"Chevy",
							"Citroen",
							"Dodge",
							"Delorean",
							"Ferrari",
							"Ford",
							"Fiat",
							"GMC",
							"GM",
							"Honda",
							"Hyundai",
							"Hummer",
							"Infiniti",
							"Jeep",
							"Jaguar",
							"Kia",
							"Lamborghini",
							"Lexus",
							"Lincoln",
							"Land Rover",
							"Maserati",
							"Mazda",
							"Mercedes",
							"Mercedes-Benz"
							"Mitsubishi",
							"Mini",
							"Maybach",
							"Nissan",
							"Oldsmobile",
//							"Opel",
							"Porshe",
							"Pontiac",
//							"Rollsroyce,"
							"RAM",
							"Subaru",
							"SAAB",
							"Suzuki",
							"Saturn",
							"Scion",
							"Tesla",
							"Toyota",
							"Volvo",
							"Volkswagen",
							"VW"
	};

	const char* car_models [] = {
							"Quattro", "A4", "A5", "A6", "S5",
							"Integra",
							"e28", "e30", "e32", "e34", "e36", "e38", "e39", "e46", "e60", "e70", "X1", "X3", "X5", "X6",
							"Escalade",
							"Corvette", "Camaro", "Silverado", "Suburban", "Tahoe", "Suburban",
							"Charger", "Challenger", "RAM", "TRX",
							"Focus", "Mustang", "F150", "F250", "F350",
							"Yukon",
							"Civic", "Type R", "Ridgeline", "Odyssey", "Prelude", "S2000",
							"Sonata", "Veloster", "Accent",
							"G37",
							"Cherokee", "Wrangler", "Rubicon",
							"Sorento", "Stinger", "Sportage", "Optima", "Forte", "Sedona",
							"Countach", "Urus", "Aventador", "Huracan", "Gallardo", "Diablo", "Murcielago",
							"Navigator",
							"Range Rover", "Evoque", "Discovery",
							"GS300", "GS 300", "GS350", "GS 350", "GS400", "GS 400", "GS430", "GS 3430", "GS460", "GS 460",
							"IS200", "IS 200", "IS250", "IS 250", "IS300", "IS 300", "IS350", "IS 350",
							"LS350", "LS 350", "LS400", "LS 400", "LS430", "LS 430",
							"SC300", "SC 300", "SC430", "SC 430",
							"Miata", "RX7", "RX-7", "RX8", "RX-8", "MX5", "MX-5", "Mazda2", "Mazda3", "Mazda6", "CX3", "CX-3", "CX30", "CX-30", "CX4", "CX-4", "CX5", "CX-5", "CX50", "CX-50", "CX60", "CX-60", "CX90", "CX-90"
							"A-Class", "B-Class", "C-Class", "E-Class", "S-Class", "AMG", "CLA", "Sprinter", "Vito", "W126", "W140", "W220", "W221", "W223", "S500", "S600", ""
							"Lancer", "Outlander", "Eclipse", "Pajero",
							"Versa", "Sentra", "Altima", "Maxima", "350Z", "370Z", "Murano", "Pathfinder", "Armada", "Frontier", "Titan",
//							"Opel",
							"911", "Boxter", "Cayman", "Carrera", "Macan", "Cayenne"
							"Firebird", "G3", "G5", "G6", "G8", "Trans AM", "Fiero", "GTO", "Bonneville", "GTO",
//							"Rollsroyce,"
							"BRZ", "Impreza", "Legacy", "Outback", "Forester", "WRX",
							"900", "9000",
							"Vitara",
							"xA", "xB", "xD", "iQ", "FR-S", "FRS", "iA", "iM", "tC",
							"Model S", "Model 3", "Model X", "Model Y",
							"AE86", "GT86", "GR86", "Camry", "Corolla", "Tundra"
							"XC40", "XC60", "XC90", "C30", "C40", "C70", "V40", "V70", "V90", "S40", "S60", "S90", "850", "940", "Polestar",
							"Golf", "Jetta", "Passat", "Touareg", "Tiguan", "Polo", "Touran", "Sharan", "Type R"
	};

	const char* phrases[] = {"Windshield banner _",
							 "Sun strip _",
							 "Sunstrip _",
							 "Windshield visor _",
							 "Windsheild sticker _",
							 "Windshield decal _",
							 "Custom windshield _"};

	for (long unsigned int i=0; i<sizeof(phrases)/sizeof(char*); i++){
		std::string phrase = phrases[i];
		std::string token = "_";

		for (long unsigned int j=0; j<(int)sizeof(car_makes)/sizeof(char*); j++){
			std::string make = car_makes[j];
			std::cout << "\"" << ReplaceAll(phrase, token, make) << "\"" << std::endl;
		}
		for (long unsigned int j=0; j<(int)sizeof(car_models)/sizeof(char*); j++){
			std::string model = car_models[j];
			std::cout << "\"" << ReplaceAll(phrase, token, model) << "\"" << std::endl;
		}
	}
	return 0;
}

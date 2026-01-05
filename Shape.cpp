#include "Shape.h"

Shape::Shape() {
	color = "red";
}

Shape::Shape(std::string color){
	if (color != "red" && color != "green" && color != "blue") {
        	throw std::invalid_argument("Invalid color");
	}

	this->color = color;
}

std::string Shape::get_color() const {
       return color;
}

void Shape::set_color(std::string c) { 
	color = c; 
}


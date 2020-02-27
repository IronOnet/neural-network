#include <iostream>
#include "NeuralNetwork.h"

int main()
{
	// Example usage: input layer has 2 neurons, output layer has 1 neuron
	NeuralNetwork nn(2, {	
		Layer(2, 2, ActivationFunctions::Type::SIGMOID),
		Layer(2, 1, ActivationFunctions::Type::SIGMOID)
	});

	// Matrix indexing example
	//Matrix matrix(3, 5);
	//std::cout << matrix << std::endl;

	//std::cout << matrix(2, 3) << std::endl;
	//std::cout << matrix[{2, 0}] << std::endl;

	// Simple training
	//nn.SimpleTraining(20000, { {{1, 0}, 1},{ { 1, 1 }, 0},{ { 0, 1 }, 1},{ { 0, 0 }, 0} });

	// SGD training
	nn.SGD(1000, 0.01, { { { 1, 0 }, 1 }, { { 1, 1 }, 0 }, { { 0, 1 }, 1 }, { { 0, 0 }, 0 } });

	std::cin.get();
	return 0;
}
#include "NeuralNetwork.h"
#include <algorithm>

double Sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

NeuralNetwork::NeuralNetwork(const std::vector<unsigned int>& layerNeurons) 
{
	for (unsigned int i = 0; i < layerNeurons.size() - 1; ++i)
	{
		// For example if the input layer has 5 neurons and the first hidden layer has 3 neurons, weight matrix is 3*5, and bias matrix is 3*1
		m_WeightMatrices.push_back(Matrix(layerNeurons[i + 1], layerNeurons[i]));
		m_Biases.push_back(Matrix(layerNeurons[i + 1], 1));
	}
}

NeuralNetwork::Output NeuralNetwork::Predict(const std::vector<double>& input) const
{
	std::vector<double> outputResults = FeedForward(input);
	unsigned int maxIndex = std::max_element(outputResults.begin(), outputResults.end()) - outputResults.begin();
	return{ outputResults[maxIndex], maxIndex };
}

NeuralNetwork::~NeuralNetwork()
{

}

std::vector<double> NeuralNetwork::FeedForward(const std::vector<double>& input) const
{
	Matrix inputMatrix(input);
	for (unsigned int i = 0; i < m_WeightMatrices.size(); ++i)
	{
		Matrix outputMatrix = m_WeightMatrices[i] * inputMatrix;
		outputMatrix += m_Biases[i];
		outputMatrix.Map(Sigmoid); // Hard-coded only for testing, will be parametrized
		inputMatrix = outputMatrix;
	}
	return inputMatrix.GetColumnVector();
}
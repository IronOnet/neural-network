#include "NeuralNetwork.h"
#include <algorithm>


// Need to build interface for activation functons
// -----------------------------------------------------
double Sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

double ReLu(double x)
{
	if (x >= 0)
		return x;
	else
		return 0;
}

double leakyReLu(double x, double alpha=0.1)
{
	double value = alpha*x;
	if (x >= value)
		return x;
	else
		return  value;
}

double ELU(double x, double alpha=0.1)
{
	if (x >= 0)
		return x;
	else
		return alpha * (exp(x) - 1);
}

double tanh(double x)
{
	return 2 / 1 + exp(-2 * x) - 1;
}
// -----------------------------------------------------


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

auto NeuralNetwork::gradientDescent(const int epochs, double learningRate, const int batchSize = 0)
{
	for (int i = 1; i <= epochs; i++)
	{
		// std::cout << "Iteration: " << i << "Cost: " << std::endl; //costFunction()

		for (int i = 0; i < m_WeightMatrices.size(); i++) // za batchSize = 0
		{
			// zero gradients
			// get output
			// calculate loss
			// backProp()
			// ... m_WeightMatrices[i] = m_WeightMatrices[i] - learningRate * layerGradients
		}
	}
}


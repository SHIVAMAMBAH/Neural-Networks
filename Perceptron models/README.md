## What is a Perceptron?
A perceptron is a fundamental building block in deep learning and machine learning, particularly in neural networks.
It was first introduced in 1958 by **Frank Rosenblatt** as a binary classifier and is designed to model the way a neuron in the brain functions.

## Simplified Perceptron Model
![X1](https://github.com/user-attachments/assets/7fedeb35-7741-4d8f-8b95-6e1a3b7d15dd)

## Structure of a Perceptron
A perceptron is essentially a linear classifier, meaning it attempts to separate data points with a straights line (or hyperplane in higher dimensions).

It chas the following main parts:
- **Input** : The perceptron recieves input values, which could represent features of the data.
- **Weights** : Each input is associated with a weight, which determines the importance of the input in making the final decision.
- **Bias** : The bias helps the perceptron model non-zero-centered data and allows shifting the decision boundry.
- **Activation Function** : The weighted sum of the input and bias is passed through an activation function which determine the output of the perceptron. In its simplest form a perceptron uses a step function, where the output is either 0 or 1 depending on whether the weighted sum is greater than or less than a threshold.

## Learning in Perceptron
The perceptron learns through a **iterative process**. It updates its weights based on the error between the predicted and actual output using a process called **gradient descent**. This learning rule adjusts the weights in proportion to the error, thereby improving the accuracy over time.  
W(new) = W(old) + 🔺W  
🔺W = n(y(true) - y(predicted))X  
where n is the learning rate.  
y(true) is the actual value   
y(predicted) is the predicted value by the model.  
X is the input.

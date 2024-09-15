#include<iostream>
#include<vector>
#include<cmath>

#define LEARNINGRATE 0.01 // lower learning rate for better stability
#define TOLERANCE 0.000001
#define maxEpoch 1000

// gives the number of rows in the dataset
size_t numberOfRows(std::vector<std::vector<double>> &Dataset){
    return Dataset.size();
}
// gives the number of columns in the dataset
size_t numberOfColumns(std::vector<std::vector<double>> &Dataset){
    return Dataset[0].size();
}

// calculates the weighted sum
std::vector<double> WeightedSum(std::vector<std::vector<double>> &Dataset,std::vector<double> &weights){
    
    size_t rows = numberOfRows(Dataset);
    size_t cols = numberOfColumns(Dataset);
    
    std::vector<double> WeightedSumVector(cols,0);
    
    for(int i = 0;i<cols;i++){
        double sum = 0;
        for(int j = 0;j<rows;j++){
            sum+=Dataset[j][i]*weights[j];
        }
        WeightedSumVector[i] = sum;
        std::cout<<"\n";
    }
    return WeightedSumVector;
}

double ReLU(double x){
    return x>=0?x:0;
}
// backpropagation algorithm
void Backpropogation(std::vector<std::vector<double>> &Dataset,std::vector<double> &targets,std::vector<double> &weights,size_t maxEpoch){
    
    size_t rows  = numberOfRows(Dataset);
    size_t cols = numberOfColumns(Dataset);
    
    double previousLoss = std::numeric_limits<double>::max();// Initialize to a large value
    
    for(size_t epoch = 0;epoch<maxEpoch;epoch++){
        std::vector<double> myvec = WeightedSum(Dataset,weights);
        double totalloss = 0;
        for(size_t i = 0;i<cols;i++){
            double Output = ReLU(myvec[i]);
            double error = targets[i]-Output;
            
            for(size_t j = 0;j<rows;j++){
                weights[j]+=LEARNINGRATE*(error)*Dataset[j][i];
            }
            totalloss+=std::pow(error,2);
        }
        if(std::fabs(previousLoss - totalloss)<TOLERANCE){
            break; // stop training if the loss improvement is below tolerance
        }
        previousLoss = totalloss;
    }
}

int main()
{
    // dataset vector, each rows acts as an independent dataset
    std::vector<std::vector<double>> Dataset = {{1,0,0,0},
                                                {0,1,0,0},
                                                {0,0,1,0},
                                                {0,0,0,1}};
    
    std::vector<double> weights = {-0.4,0.3,-0.1,0.7}; // weights initialised randomly
    std::vector<double> targets = {1,1,1,1}; // target output for each flattened row
    
    Backpropogation(Dataset,targets,weights,maxEpoch);
    std::cout<<"New Weight Vector"<<"\n";
    // printing the new updated weights
   for(double w:weights){
        std::cout<<w<<" ";
    }
    return 0;
}

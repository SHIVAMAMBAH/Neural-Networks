#include<iostream>
#include<vector>

#define LEARNINGRATE 0.01

size_t numberOfRows(std::vector<std::vector<double>> &Dataset){
    return Dataset.size();
}

size_t numberOfColumns(std::vector<std::vector<double>> &Dataset){
    return Dataset[0].size();
}

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

std::vector<double> Backpropogation(std::vector<std::vector<double>> &Dataset,std::vector<double> &myvec,std::vector<double> &weights){
    
    std::vector<double> newWeightVector(4,0);
    
    for(int i = 0;i<myvec.size();i++){
        double result = ReLU(myvec[i]);
        std::vector<double> subset = Dataset[i];
        while(result<1){
            weights[i] = weights[i] + LEARNINGRATE*(1- result)*subset[i];
            myvec[i] = myvec[i] + WeightedSum(Dataset,weights)[i];
            result = ReLU(myvec[i]);
        }
        newWeightVector[i] = result;
    }
    
  return newWeightVector;
  
}

int main()
{
    
    std::vector<std::vector<double>> Dataset = {{1,0,0,0},
                                                {0,1,0,0},
                                                {0,0,1,0},
                                                {0,0,0,1}};
    
    std::vector<double> weights = {-0.4,0.3,-0.1,0.7};
    std::cout<<"Weights Vector : "<<"\n";
    for(int i = 0;i<weights.size();i++){
        std::cout<<weights[i]<<" ";
    }
    std::cout<<"\n";
    std::vector<double> myvec = WeightedSum(Dataset,weights);
    std::cout<<"Weighted Sum vector : "<<"\n";
    for(int i = 0;i<myvec.size();i++){
        std::cout<<myvec[i]<<" ";
    }
    
    std::cout<<"\n";
    std::cout<<"Output vector: "<<"\n";
    for(int i = 0;i<myvec.size();i++){
        std::cout<<ReLU(myvec[i])<<" ";
    }
    std::cout<<"\n";
    
    std::vector<double> newWeightVector = Backpropogation(Dataset,myvec,weights);
    std::cout<<"New Weight Vector"<<"\n";
    for(int i = 0;i<newWeightVector.size();i++){
        std::cout<<ReLU(newWeightVector[i])<<" ";
    }
    
    return 0;
}

using namespace std;
#include <iostream>
#include<cmath>
#include<vector>
#include<random>
#include <chrono>
int main()
{
        double S0, r, T, sigma,K;
        double CallOption(double S0,double r,double T,double sigma,double K);
        double Asian(double S0,double r, double T, double sigma, double K);
        cout<<"Enter spot price"<<endl;
        cin>>S0;
        cout<<"Enter rate"<<endl;
        cin>>r;
        cout<<"Enter maturity"<<endl;
        cin>>T;
        cout<<"Enter volatility"<<endl;
        cin>>sigma;
        cout<<"Enter strike"<<endl;
        cin>>K;
        double stock[100];
        double sum;
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator (seed);
        normal_distribution<double> distribution (0.0,1.0);
        double St=S0;

        double Z=distribution(generator);

        cout<<Z;

        cout<<"The Call Option price is:"<<" "<<CallOption(S0,r,T,sigma,K);
        cout<<"Asian Option price is: "<<" " <<Asian(S0,r,T,sigma,K);
}
double CallOption(double S0,double r,double T,double sigma,double K)
{
        int numpaths;
        double diff;

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator (seed);
        normal_distribution<double> distribution (0.0,1.0);
        double total;
        for(int i=1;i<=1000;i++)
        {
        double Z=distribution(generator);
        double ST=S0*exp((r-pow(sigma,2)/2)*T+sigma*sqrt(T)*Z);
        if (ST>K) {
        diff=ST-K;
        }
        else {
        diff=0;
        }
        total+=diff;
        }

        return exp(-r*T)*total/1000;
}
double Asian(double S0, double r, double T, double sigma, double K)

{
double stock[100];
double diff[100000];
double store[1000];
double sum;
double avg;
double St=S0;
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator (seed);
        normal_distribution<double> distribution (0.0,1.0);

        for(int i=1;i<=100000;i++) {
        St=S0;
        sum=0;

        for (int k=1;k<=100;k++) {
        double Z=distribution(generator);
        stock[k]=St*exp(((r-pow(sigma,2)/2)*T/100)+sigma*sqrt(T/100)*Z);
        St=stock[k];
        sum+=stock[k];

        }
        store[i]=sum/100;
        if(store[i]>K) {
        diff[i]=store[i]-K;
        }
        else{
        diff[i]=0;
        }
        }
        for (int j=1;j<=100000;j++){
        avg+=diff[j];
        }
return exp(-r*T)*avg/100000;
}

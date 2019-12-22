#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// A Naive recursive C++ program to find minimum of coins 
// to make a given change V 
#include<bits/stdc++.h> 
using namespace std; 
//#include <chrono>

// m is size of coins array (number of different coins) 
int minCoinsD(int coins[], int m, int V) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
    int table[V+1]; 
  
    // Base case (If given value V is 0) 
    table[0] = 0; 
  
    // Initialize all table values as Infinite 
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  
    // Compute minimum coins required for all 
    // values from 1 to V 
    for (int i=1; i<=V; i++) 
    { 
        // Go through all coins smaller than i 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
   
	} 
    return table[V]; 
} 

// m is size of coins array (number of different coins) 
int minCoins(int coins[], int m, int V,int level) 

{

 level++;
 
   // base case 
   if (V == 0) return 0; 
  
   // Initialize result 
   int res = INT_MAX; 
     
   // Try every coin that has smaller value than V 
   for (int i=0; i<m; i++) 
   { 
   
     if (coins[i] <= V) 
     { 
        
        int sub_res = minCoins(coins, m, V-coins[i],level); 
        
	
         // Check for INT_MAX to avoid overflow and see if 
         // result can minimized 
         if (sub_res != INT_MAX && sub_res + 1 < res) 
            res = sub_res + 1; 
          
  
            
     } 
   }

   return res; 
} 


int minCoinsM(int coins[], int m, int V) 

{

 
   // base case 
   if (V == 0) return 0; 
  
   // Initialize result a
   int res = INT_MAX; 
   int whole_part = 0;
int remainder = 0;
  
   // Try every coin that has smaller value than V 
   for (int i=0; i<m; i++) 
   { 
     if (coins[i] <= V) 
     { 
       
        whole_part = V/coins[i];
		remainder = V%coins[i];
        int sub_res = minCoinsM(coins, m, V-(coins[i]*whole_part)); 
        
	
  
         // Check for INT_MAX to avoid overflow and see if 
         // result can minimized 
         if (sub_res != INT_MAX && sub_res + 1 < res) 
            res = sub_res + 1; 
     } 
   }
 
   return res; 
} 



int main(int argc, char** argv) {
	// Driver program to test above function 


     
    int m = 1; 
    int V = 15;
    cout << "Cantidad a dividir: ";
	cin >> V; 
	
	cout << endl << "Cantidad de tipos de moneda: ";
	cin >> m;
	
	
	int coins[m];
	
	for (int i = 0; i < m; i++){
		cout << "Valor para el tipo de moneda " << i << ": ";
		cin >> coins[i];
		cout << endl;
	}
    
    cout << "Cantidad mínima de monedas utilizando método recursivo es "
         << minCoins(coins, m, V,0) << " para dar feria de: " << V << endl; 

 cout << "Cantidad mínima de monedas utilizando método dinámico es "
         << minCoinsD(coins, m, V) << " para dar feria de: " << V << endl; 
   
   
    return 0; 

}


  


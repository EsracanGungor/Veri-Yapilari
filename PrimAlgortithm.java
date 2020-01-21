package primalgorithm;

import java.util.Scanner;
import java.io.*;
import java.util.InputMismatchException;

class Graph {

    int graph[][];
    int vertice, edge;
    int d[], parent[], visited[];
    int u,v;
   

    public void createGraph()  {
      int source, destination, cost;
      boolean bln=false;
        Scanner scanner = new Scanner(System.in);
        try{
          System.out.println("Enter number of vertices(1-10)");
          vertice = scanner.nextInt();
         
            if(vertice==0 || vertice>10){
              System.out.println("Please enter a number within the specified range.Enter a number again..");
              vertice = scanner.nextInt();
                while(bln==false){
                    vertice = scanner.nextInt();
                    if(vertice<10 && vertice>0){
                        bln=true; }
                }
            }
        }catch(Exception e1){
            System.out.println("please enter the appropriate type of data=Integer!"+e1.getMessage());
            System.exit(1);
        }
       
       
        try{
           System.out.println("Enter number of edges(1-15)");
           edge = scanner.nextInt();
           if(edge==0 || edge>15){
              System.out.println("Please enter a number within the specified range.Enter a number again..");
              edge = scanner.nextInt();
                while(bln==false){
                    edge = scanner.nextInt();
                    if(edge>0 && edge<15){
                        bln=true; }
                }
            }
        }catch(Exception e1){
            System.out.println("please enter the appropriate type of data=Integer!"+e1.getMessage());
            vertice = scanner.nextInt();
            System.exit(1);
        }
       
       
        graph = new int[vertice + 1][vertice + 1];
        for (int i = 1; i <= vertice; i++) {
            for (int j = 1; j <= vertice; j++) {
                graph[i][j] = 0;
            }
        }
       
        System.out.println("Enter node1-node2-cost information(in the same order )");
        for (int i = 1; i <= edge; i++) {
            source = scanner.nextInt();
            destination = scanner.nextInt();
            try{
            cost = scanner.nextInt();
            graph[source][destination] = graph[destination][source] = cost;
            }catch(InputMismatchException e1){
            System.out.println("Please enter the appropriate type of data=Integer!"+e1.getMessage());
            System.exit(1);
            }
        }
    }

    public void callPrim() {
        visited = new int[vertice + 1];
        d = new int[vertice + 1];
        parent = new int[vertice + 1];
        for (int i = 1; i <= vertice; i++) {
            parent[i] = visited[i] = 0;
        }
        for (int i = 1; i <= vertice; i++) {
            d[i] = 32767;
        }
        primsAlgorithm();
    }
   

   public void primsAlgorithm() {
        int c, current, mincost = 0;
        current = 1;
        visited[current] = 1;
        d[current] = 0;
        c = 1;
        while (c != vertice) {
            for (int i = 1; i <= vertice; i++) {
                if (graph[current][i] != 0 && visited[i] != 1) {
                    if (graph[current][i] < d[i]) {
                        d[i] = graph[current][i];
                        parent[i] = current;
                        u=current;
                        v=i;

                    }
                }      

            }                                                      
           
            int min = Integer.MAX_VALUE;
            for (int i = 1; i <= vertice; i++) {
                if (visited[i] != 1 && d[i] < min) {
                    min = d[i];
                    current = i;
                }
            }
            visited[current] = 1;
            c = c + 1;
        }
        for (int i = 1; i <= vertice; i++) {
            mincost += d[i];
           
}
        System.out.println("Minimum cost= " + mincost);
    }

  void printMST()
    {         System.out.println("Minimum Spaning Tree:");

        System.out.println("Edge \tWeight");
        for (int i = 2; i <=vertice; i++)
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
    }
}
public class PrimAlgorithm {
    public static void main(String[] args)  {
        Graph sample = new Graph();
        sample.createGraph();
        sample.callPrim();
        sample.printMST();
    }
}

/**
 * Copyright 2015 Silvana Trindade
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "Graph.hpp"
#include "TreeNode.hpp"
#include <thread>
#include <mutex>
#include <utility>

class BalancedTree
{
public:

	BalancedTree();
	~BalancedTree();


	void execute(Graph &,string);
	void averageHops(Graph);
	void discardCommonEdge(vector<int> &, vector<int> &, int, int);	//gera dois novos caminhos excluindo os enlaces em comum
	/**
	 * Métodos para encontrar caminhos balanceados
	 */
	bool searchPath(vector< vector<int> >, vector<int> );
	void findPairOfBalancedPaths(Graph,int,int);		//grafo construído a partir dos caminhos mínimos encontrados pelo algoritmo de BalancedSuurballe, e a origem e destino
	vector< vector<int> > findAllPaths(Graph,int,int);					//retorna todos os caminhos encontrados da origem ao destino
	vector<int> returnPath(TreeNode *);									//retorna novo caminho, sobe do filho até o pai construindo o caminho
	bool isNodeInPath(TreeNode *,int);									//verifica se o nó já existe em um caminho
	void addChildren(Graph,TreeNode *,int,int,vector< vector<int> > &); //Adiciona recursivamente os filhos do nó root passado como parâmetro
	void freeTree(TreeNode *);
	void makePathVector(vector<int>,vector<int> &, vector<int> &);											//desaloca memória da árvore
	vector< vector<int> > compareWithOthers(Graph g,vector<int> &, vector<int> &);					//compara dois caminhos, verificando se existe arestas iguais
	void printPaths(vector<int>, vector<int>,Graph &);

private:

	mutex m;
	mutex dic;
	vector< double> hopWorking;					//número de saltos(i,j) do principal
	vector< double> hopBackup;					//número de saltos(i,j) de backup
	vector<pair<int,int>> distance;
	ofstream datas;//arquivo para armazenar caminhos de trabalho e backup	
};
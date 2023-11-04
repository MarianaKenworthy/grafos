
# Implementação de grafos

## Descrição:
  O objetivo deste trabalho é implementar uma estrutura de dados para manipular Grafos usando linguagem C ou C++ e operações para manipular os grafos. Crie as structs ou classes que julgar necessário para manipular os grafos.

## As seguinte operações devem ser implementadas:
- Ler um arquivo .txt contendo um grafo. O arquivo terá o seguinte formato

	  1a linha  <num_vertices> <num_arestas ou arcos> <tipo> <valorado>
	  Linhas seguintes: para cada aresta ou arco {vi , vj}, criar uma linha com o formato <vi> <vj> <peso>

  OBS:
	 - <tipo> será G para grafo não dirigido e D para grafo dirigido  
	  - <valorado> será 1 paragrafo valorado e 0 para grafo não valorado  
	  - <peso> é opcional e só existirá para grafo ponderado  
	  - Arestas ou arcos paralelos aparecerão mais de uma vez no arquivo   
a 
- Gerar um arquivo .txt contendo um grafo, com o formato definido em (a)
- Converter de matriz de adjacências para lista de adjacências (e vice-versa)
- Calcular e mostrar o grau de cada vértice
- Encontrar uma árvore geradora mínima
- Encontrar um caminho mais curto usando Dijkstra
- Realizar Busca em largura
- Realizar Busca em profundidade

# DesenhoGrafico-ITP  
Projeto da terceira unidade da disciplina de Introdução às Técnicas de Programação do Bacharelado de Tecnologia da Informação da UFRN 2019.2  
Alunos: Brenda Alexandra e José de Sousa.  


## Funções básicas  
  - makeLine (Brenda)  
  - makePolygon (Brenda)  
  - makeCircle (Brenda)  
  - makeRect (José)  
  - fillForm (José)  
  
  - makeImage (Brenda)  
  - cleanImage (José)  
  - colorImage (José)  
  - saveImage (José)  
  
## Funções extras  
 - negative (Brenda): gera uma imagem negativa da imagem original;  
 - threshold (Brenda): gera uma imagem (com valores 0 ou 255) de acordo com o limiar inserido;   
 - reduce (Brenda): gera uma imagem reduzida em 50% da imagem original;  
 - makePolygon3D (José): gera um polígono 3D com profundidade de 10 pixels.  
 
    O que seria feito diferente: 1) A função reduce seria alterada para reduzir para qualquer comprimento x largura; 2) A função makePolygon3D seria alterar para receber a profundidade (em pixels) na linha de comando do arquivo TXT.
## Como inserir valores no arquivo .txt
  Funções básicas:
  - makeLine: uma string "line" seguido de 2 coordenadas (x,y); 
  - makePolygon: uma string "polygon" seguindo de um valor N (quantidade de pontos do polígono) e as N coordenadas (x,y) do polígono;
  - makeCircle: uma string "circle" seguido de uma coordenada (x,y), sendo o ponto de origem do círculo, e o raio do círculo;    
  - makeRect: uma string "rect" seguido de uma coordenada (x,y), altura e largura; 
  - fillForm: uma string "fill" seguido de uma coordenada (x,y);
  - makeImage: uma string "image" seguido do comprimento e altura da imagem;   
  - cleanImage: uma string "clear" seguido de 3 valores referentes as cores no modelo RGB, respectivamente;  
  - colorImage: uma string "color" seguido de 3 valores referentes as cores no modelo RGB, respectivamente;
  - saveImage: uma string "save" seguido de uma string com o "nome_da_imagem.ppm"; 
  
  Funções extras:
  - negative: uma string "negative";  
  - threshold: uma string "threshold" seguido de um limiar desejado;
  - reduce: uma string "reduce";
  - makePolygon3D: uma string "makePolygon3D" seguido de um valor N (quantidade de pontos do polígono) e as N coordenadas (x,y) do polígono.
  
  Observações: Todos os valores inseridos devem ser números inteiros e uma coordenada (x,y) é inserida como 2 valores x e y separados.
## Como compilar  
No terminal, dentro da pasta do projeto execute os seguintes comandos:  

> make all  
> ./main
  Observação: nenhuma biblioteca externa foi utilizada. 




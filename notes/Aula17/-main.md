# Tipos de analisadores sintáticos

- **Tipos Universais**: Como o algoritmo de Younger-Kasami e o algoritmo de Early;
- **Top-down**: raiz -> folhas;
- **Bottom-up**: folhas -> raiz; 

## Tipos Universais
São métodos que funcionam para qualquer tipo de gramática, porém têm complexidade assintótica alta, por isso não usados para um compilador em produção, apenas de forma teórica.

## Top-down
Há preferência de implementar analisadores top-down, porque eles se utilizam da recursão e geram uma árvore sintática implícita (pilha abstrata da recursão)

## Bottom-up
Mais difícil de implementar, tem que ser implementado de maneira iterativa e usando uma pilha explícita, portanto a árvore sintática é construída de maneira explícita.

# Tipos de erros que um compilador pode encontrar

1. Erros léxicos: `int x = 'abç';` - As aspas simples ' ', na linguagem C, são destinadas a um único caractere.
2. Erros sintáticos: `int 2x = 2 * x;` - Em linguagem C, o nome de um identificador não pode começar com um número, apesar de **'2'** e **'x'**, serem tokens válidos, sintaticamente, há um erro.
3. Erros semânticos: `int x = "abç";` - Há inconformidade de tipos, uma variável inteira recebe uma string.
4. Erros lógicos: Div por 0, array fora de memória, etc...*Div por 0, array fora de memória, etc...*

## Tratamento de erros sintáticos

Um tratador de erros sintáticos possui 3 principais metas:

1. Relatar a presença de erros de maneira clara e precisa;
2. Recuperar-se de cada erro o mais rápido e identificar erros subsequentes;
3. Não atrasar o processamento de programas corretos sintaticamente;

Uma vez encontrado um erro, o tratador deve sinalizar a natureza e a localização deste erro, pode indicar a linha do código fonte do erro em questão. Se possível, deve ser sinalizada uma mensagem indicando a natureza do erro e uma possível correção. 

## Estratégia de recuperação de erros

Existem 4 principais maneiras de se recuperar de um erro:

1. Desespero - Ao descobrir um erro, o compilador segue descartando símbolos de entrada até encontrar um delimitador. Esta é a mais simples e tem garantia de não entrar em loop infinito.
2. Recuperação de frases - É feita uma pequena correção local que permita o analisador seguir a diante, um exemplo poderia ser inserir um ponto-e-e-vírgula. Não é ideal em casos onde o erro ocorreu antes do token em questão.
3. Produções de erro - Insere na gramática, de forma proposital, produções ilegais de erros comumente cometidos na gramática, aumenta a precisão do analisador e das sugestões de correção, contudo afeta o desempenho por conta das verificações adicionais realizadas.
4. Correção global - O compilador realiza o mínimo de correções na entrada para que essa fique válida. Se baseia na ideia de que a maior parte dos erros pode ser corrigida com poucas alterações. Grande custo de tempo e memória, além disso pode causar modificações comportamentais no programa.

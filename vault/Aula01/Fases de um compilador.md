Conceitualmente um compilador opera em fases. Cada fase manipula o programa fonte e entrega para a próxima fase. Porém, na prática algumas fases podem operar de forma conjunta, e a representação intermediária entre elas pode não ser construída explicitamente. As três primeiras pertencem a Análise e as três últimas a Síntese, como visto na seção de [Análise e Síntese](Análise%20e%20Síntese.md) Mas, existem duas fases que interagem durante toda a a compilação, a **Gerência da Tabela de Símbolos** e o **Tratamento de Erros**.

[Fases de um compilador](Fases%20de%20um%20compilador.md)
# Gerenciamento da tabela de símbolos
Esta atividade registra os identificadores do programa alvo, e identifica seus diversos atributos, como , nome, tipo, memória, escopo, etc. Caso este identificador se refira a um procedimento (função) devem ser guardados a quantidade de parâmetros,  os respectivos tipos e o tipo de retorno.

# Tratamento de erros
A cada fase da compilação podem ocorrer um ou mais erros, o compilador deve tratar estes erros, e, se possível, continuar em busca de mais erros. Abortar a compilação no primeiro erro pode diminuir a eficiência do compilador. Nas fases da análise sintática e semântica é onde ocorrem a maior quantidade de erros. 

Exemplo da parte de análise de um programa fonte
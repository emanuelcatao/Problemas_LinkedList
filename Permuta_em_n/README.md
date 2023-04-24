# Lista de phi

<p align='justify'> Como você já deve ter percebido, o uso de listas para representar sequências ou conjuntos de elementos que compartilham determinada propriedade é bastante comum no mundo real. É também natural que se sinta a necessidade de, diante de uma lista, alterar a ordem dos elementos dentro dessa lista para uma que nos seja mais significativa. Nessa atividade você deve implementar uma operação para alterar um pouco a ordem dos elementos dentro dessa lista. A operação que será implementada é a de inversão e ela funciona da seguinte maneira:
</p>

<p align='justify'> 1:  Tendo recebido uma lista completa na entrada e um número inteiro N, o programa deve inverter os elementos entre i e  i + (N - 1).

Obs: N é um inteiro menor ou igual ao tamanho da lista. Se o número de nós não é um múltiplo de N, então haverão nós no final da lista que permanecerão como estão. Além disso, não é permitido alterar os valores dos nós, apenas os próprios nós é que deverão ser trocados de posição.
</p>


<p align='justify'><b>Entrada:</b> Cada entrada é composta por uma lista de valores (separados por um espaço em branco) e por um inteiro positivo, separados por uma quebra de linha

<b>Saída:</b> Deve-se retornar a lista com as permutações efetuadas. O valor de cada nó da lista deve ser separado por um espaço, uma seta, no formato indicado nos exemplos, e mais um espaço (incluindo o último nó). Após imprimir o último número da lista, deve-se quebrar a linha (‘\n’) (vide exemplos a seguir).</p>

<p align='justify'> O objetivo desse miniprojeto é construir em código C, um programa que, dado um número natural qualquer, construa uma lista dinâmica formada por esse o número, bem como pelo totiente do totiente de cada número contido na lista, até que se chegue ao número um. Exemplo:</p>
<p align='center'>ϕ(n)  = m
<br>ϕ(m)  = q
<br>ϕ(q)  = b
<br>ϕ(b)  = a
<br>ϕ(a)  = 1</p>
<p> Logo essa lista será: </p>
<p align='center'> m -> q -> b -> a -> 1  </p>

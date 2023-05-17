# Ordenação de Lista Bitônica

<p align='justify'> Um tipo interessante de sequência numérica é chamado de Sequência Bitônica. Uma sequência pode ser dita monotonicamente crescente quando ela é equivalente a uma sequência não-decrescente, ou seja, seus elementos nunca diminuem, mas podem ficar iguais. Uma sequência também pode ser dita monotonicamente decrescente, cuja definição é análoga ao tipo anterior. Já uma sequência bitônica, é uma sequência monotonicamente crescente seguida de uma monotonicamente decrescente (ou uma rotação cíclica dessa sequência).</p>
<p align='justify'> Pede-se que seu programa construa uma lista duplamente encadeada a partir da lista bitônica fornecida na entrada e imprima uma lista ordenada, partindo da lista criada e seguindo o seguinte método:
</p>
<p align='justify'>
Exemplo de lista: [1, 2, 4, 3]
</p>
<ul>
    <li>Mantenha os dois ponteiros: inicio e fim da lista. Do exemplo: (inicio = 1, fim = 3)</li>
    <li>Compare ambos os valores dos nós e adicione o elemento menor para resultar em uma lista. Do exemplo: (inicio < fim)</li>
    <li>Compare o próximo elemento adjacente ao elemento adicionado com aquele que não foi adicionado e adicione o menor  (inicio->prox, se inicio < fim; fim->ant, se fim < inicio).</li>
    <ul>
        <li>Do exemplo: inicio é adicionado; compare (inicio->prox = 2, fim = 3).</li>
        <li>inicio->prox é adicionado</li>
    </ul>
    <li>Repita isso até que todos os elementos da lista duplamente encadeada criada a partir da entrada sejam adicionados ao resultado da ordenação. </li>
    <ul> 
        <li>Compare (inicio->prox->prox = 4, fim = 3).</li>
        <li>fim é adicionado</li>
        <li> Compare (inicio->prox->prox, fim->ant)</li>
        <li>inicio->prox->prox é adicionado</li>
        <li>Todos os elementos foram adicionados. Lista final: [1, 2, 3, 4]</li>
    </ul>
</ul>
</p>

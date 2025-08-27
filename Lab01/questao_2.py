class Lista():
    def __init__(self):
        self.items = []

    def adicionar(self, item):
        self.items.append(item)

    def recuperar(self, index):
        if 0 <= index < len(self.items):
            return self.items[index]
        return None

class Pilha():
    def __init__(self):
        self.items = []

    def empilhar(self, item):
        self.items.append(item)

    def desempilhar(self):
        if not len(self.items) <= 0:
            return self.items.pop()
        return None
    
class Fila():
    def __init__(self):
        self.items = []

    def enfileirar(self, item):
        self.items.append(item)

    def desenfileirar(self):
        if not len(self.items) <= 0:
            return self.items.pop(0)
        return None
    
lista = Lista()

lista.adicionar(10)
lista.adicionar(20)
lista.adicionar(30)

print("Valor no índice 1 da lista:", lista.recuperar(1))  # Deve imprimir 20

pilha = Pilha()

pilha.empilhar(10)
pilha.empilhar(20)
pilha.empilhar(30)

print("Valor desempilhado da pilha:", pilha.desempilhar())  # Deve imprimir 30

fila = Fila()

fila.enfileirar(10)
fila.enfileirar(20)
fila.enfileirar(30)

print("Valor desenfileirado da fila:", fila.desenfileirar())  # Deve imprimir 10
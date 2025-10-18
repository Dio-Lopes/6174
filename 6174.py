kaprekar_constant = 6174

def hasTwoDifferentDigits(n):
    s = str(n).zfill(4)
    return len(set(s)) > 1

# Função principal que executa a rotina de Kaprekar
def kaprekarsRoutine(num):
    iterations = 0
    result = int(num) # Preparar
    while result != kaprekar_constant: # Enquanto não chegar a 6174
        s = str(result).zfill(4)
        ascendente = int(''.join(sorted(s)))
        descendente = int(''.join(sorted(s, reverse=True)))
        result = descendente - ascendente
        iterations += 1
    return result, iterations

# Início
while True:
    chosenNum = input("Escolhe um número com 4 algarismos, com, pelo menos, dois digitos diferentes!\n")

    # Validação do número
    # Se o número não tiver 4 dígitos, ou não for numérico, ou não tiver pelo menos dois dígitos diferentes, é inválido
    if len(chosenNum) != 4 or not chosenNum.isdigit() or not hasTwoDifferentDigits(chosenNum):
        print("Número inválido!\n")
    else:
        break

# Executa a rotina de Kaprekar
result, iterations = kaprekarsRoutine(chosenNum)
# Conclusão
# Mostrar resultado e número de iterações
print(f"Acabou! O resultado deu: {result}")
if iterations == 1:
    print(f"Efetuamos a operação de Kaprekar {iterations} vez.")
else:
    print(f"Efetuamos a operação de Kaprekar {iterations} vezes.")
input("\nPressione Enter para sair...")
import subprocess
import random

# Caminhos para os executáveis
MEU_PROGRAMA = './meu'         # ou 'meu.exe' no Windows
CORRETO_PROGRAMA = './correto' # ou 'correto.exe' no Windows

def gerar_teste():
    y = random.randint(1, 10**9)
    k = random.randint(1, 10**9)
    return y, k

def rodar_programa(exec_path, entrada):
    """Executa o programa com a entrada e retorna a saída como string"""
    resultado = subprocess.run(exec_path, input=entrada.encode(),
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return resultado.stdout.decode().strip()

def main():
    l = [(1, 10**9), (10**9, 1)]
    for tentativa in range(1, len(l)):  # Muito testes, até achar falha
        y, k = l[tentativa]
        entrada = f"{y} {k}\n"
        
        # Log detalhado
        print(f"Teste #{tentativa}: y = {y}, k = {k}")
        
        saida_meu = rodar_programa(MEU_PROGRAMA, entrada)
        saida_correto = rodar_programa(CORRETO_PROGRAMA, entrada)
        
        if saida_meu != saida_correto:
            print(f"\n❌ Falha encontrada no teste #{tentativa}")
            print(f"Entrada: y = {y}, k = {k}")
            print(f"Saída do meu programa: {saida_meu}")
            print(f"Saída do correto: {saida_correto}")
            break
        
        if tentativa % 1000 == 0:
            print(f"✅ {tentativa} testes realizados sem erro até agora...\n")

if __name__ == "__main__":
    main()

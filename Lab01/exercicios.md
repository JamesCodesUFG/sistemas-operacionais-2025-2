1. ⭐⭐ Defina em termos próprios os seguintes conceitos, apontando
exemplos do seu uso na prática, em até cinco frase por definição.
    * Sistema Operacional
    * BIOS
    * API
    * Chamada de sistema
    * Kernel

    > **Resposta**:
    > * Sistema Operacional: é o software que gerencia os recursos de um dispositivo. Ele é a metade do caminho usuário/hardaware. É o único software que fica ativo 100% do tempo.
    > * BIOS: é o sistema basico de entrada/saída. A BIOS é um firmware responsável por realizar a inicialização do hardwarer durante o processo de inicialização. É o primeiro software a ser executado.
    > * API: é a interface de programação de aplicações. São serviços e funções prontas que podem ser utilizadas por outras implementações diretamente de forma simplificada.
    > * Chamada de sistema: 
    > * Kernel: 

2. ⭐⭐⭐ Descreva a funcionalidade das cinco principais estruturas de dados
utilizadas na implementação dos sistemas operacionais, isto é, listas, pilhas, filas, função hash e bitmap.
    * Escolha duas opções dentre as cinco e escreva um exemplo do uso destas estruturas em código. A escolha da linguagem fica ao seu critério (e.g., C/C++, Java, Python, Rush, Go, etc.)

    > **Resposta**:  
    > Listas: estrutura de dados que capaz de armazenar elementos, que podem ser acessados de forma aleatória.  
    > Pilhas: estrura de dados capaz de armazenar elementos, de forma que o último valor inserido é sempre o primeiro valor lido.  
    > Filas: estrutura de dados capaz de armazenar elementos, de forma que o primeiro elemento a entrar é o primeiro elemento a ser lido.  
    > Função hash: é uma função que mapeia dados de comprimento variável para dados de comprimento fixo.
    > Bitmap:  --

3. ⭐ O que é uma API? qual é a sua utilidade dentro do sistema operacional?
que relação que guarda com as chamadas de sistema?

    > **Resposta**:  
    > Uma API é um conjunto de regras que permite que diferentes programas se comuniquem. Dentro de um sistema operacional, ela serve como uma ponte para que os aplicativos acessem os serviços e recursos do sistema, como o disco rígido ou a rede, de forma segura.  
    > A relação com as chamadas de sistema é que a API é a interface de alto nível que os desenvolvedores usam. Essa interface, por sua vez, aciona as chamadas de sistema, que são as instruções de baixo nível que o programa envia diretamente ao núcleo do sistema operacional (o kernel) para realizar tarefas específicas.

4. ⭐ Qual é o nome da API que utilizam os sistemas Windows, Unix (e.g. Solaris, Linux, MacOS X) e Java Virtual Machine (JVM) e quais são as suas
principais características?

    > **Resposta**: 
    > * Windows: Usa a Windows API (WinAPI), que é extensa, complexa e baseada em um modelo de mensagens para interagir com a interface gráfica.
    > * Unix (Linux, macOS): Compartilham o padrão POSIX, que foca na filosofia "tudo é um arquivo" e é mais próximo das chamadas de sistema, com foco no gerenciamento de processos.
    > * Java (JVM): Usa a Java API, que é a principal responsável pela independência de plataforma do Java, permitindo que o mesmo código rode em diferentes sistemas operacionais.

5. ⭐ Descreva cinco chamadas de sistema utilizadas nos sistemas Unix
detalhando sua sintaxe e a operação que executam. Cada função deverá
pertencer a uma categoria diferente, sejam elas “Process control”, “File
management”, “Device management”, “Information Maintenance”, “Communication” e “Protection”.

    > **Resposta**:
    As cinco chamadas de sistema no Unix são:
    > 1. fork() (Controle de Processo) 
    >       * Sintaxe: `pid_t fork(void);`
    >       * Cria um novo processo, que é uma cópia exata do original.
    > 2. read() (Gerenciamento de Arquivo)
    >       * Sintaxe: `ssize_t read(int fd, void *buf, size_t count);`
    >       * Lê dados de um arquivo ou dispositivo.
    > 3. ioctl() (Gerenciamento de Dispositivo)
    >       * Sintaxe: `int ioctl(int fd, unsigned long request, ...);`
    >       * Faz operações de controle específicas em um dispositivo de hardware.
    > 4. getpid() (Manutenção de Informação)
    >       * Sintaxe: `pid_t getpid(void);`
    >       * Retorna o ID do processo atual.
    > 5. pipe() (Comunicação)
    >       * Sintaxe: `int pipe(int pipefd[2]);`
    >       * Cria um canal para a comunicação entre processos.

6. ⭐ O que é uma máquina virtual? e um container? Cite dois exemplos do
seu uso na atualidade.

    > **Resposta**: 
    > Uma máquina virtual (VM) é um ambiente de software que simula um computador completo, com seu próprio sistema operacional e hardware virtual.  
    > Um container é um ambiente isolado que compartilha o mesmo kernel do sistema operacional do host. Ele empacota apenas o aplicativo e suas dependências, tornando-o mais leve e rápido que uma VM.  
    > Seus usos na atualidade são hospedagem de servidores e desenvolvimento de software.

7. ⭐⭐ Descreva o princípio de funcionamento do programa bootstrap e da
memória cache.

    > **Resposta**:
    > * Bootstrap: O bootstrap é o processo inicial de inicialização de um sistema operacional. Ao ligar o computador, a CPU executa um pequeno código de um firmware (como o BIOS/UEFI) que está na placa-mãe. Este código, chamado de carregador de inicialização (boot loader), tem a única função de carregar o sistema operacional da memória de massa (disco rígido) para a memória principal (RAM) e, em seguida, transferir o controle para ele.
    > * Cache: A memória cache é um tipo de memória volátil extremamente rápida e pequena, localizada entre o processador (CPU) e a memória principal (RAM). Seu princípio de funcionamento se baseia na localidade de referência, que assume que os dados e instruções que a CPU usou recentemente serão usados novamente em breve.  
    > A cache armazena cópias dos dados mais acessados da RAM. Quando a CPU precisa de uma informação, ela primeiro verifica se os dados estão na cache. Se estiverem (um cache hit), o acesso é quase instantâneo. Se não estiverem (um cache miss), a CPU busca os dados na RAM, e uma cópia é armazenada na cache para uso futuro. Isso reduz drasticamente o tempo de espera do processador, melhorando o desempenho geral do sistema.

8. ⭐⭐ Quando trabalhamos com Gestão de Projetos e Processos definimos as
metodologias de desenvolvimento de projetos de software mais importantes
utilizadas na atualidade. Defina em até cinco frases por item uma
metodologia utilizada para:
    * Gestão de projetos
    * Gestão de processos

    > **Resposta**: 
    > * Scrum: é uma metodologia ágil e iterativa para a gestão de projetos complexos, focada em entregas incrementais. O trabalho é dividido em ciclos curtos e fixos, chamados Sprints, que geralmente duram de uma a quatro semanas. A equipe, que é auto-organizada e multifuncional, se reúne diariamente em uma "Daily Scrum" para sincronizar o progresso. Ao final de cada Sprint, há a entrega de um incremento funcional do produto e uma revisão para planejar a próxima iteração. O objetivo é permitir que as equipes se adaptem rapidamente às mudanças e entreguem valor de forma contínua.
    > * BPM: é uma abordagem disciplinada para identificar, modelar, analisar, melhorar e automatizar os processos de uma organização. O foco principal é alinhar todos os processos de negócio com os objetivos estratégicos da empresa. O ciclo de BPM é contínuo e visa a melhoria constante da eficiência, redução de custos e aumento da qualidade dos produtos ou serviços. Diferente da gestão de projetos, que tem um início e fim definidos, a gestão de processos é uma disciplina de longo prazo, buscando a otimização contínua.
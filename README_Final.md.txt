Portafolio Profesional: Documentación y Calidad de Código README.md

Este proyecto implementa un sistema de control de personaje en C++ utilizando patrones de diseño clave como Command, State y Observer. Permite manejar entradas del jugador, estados del personaje, acciones y eventos de manera escalable.

Índice de Patrones Implementados

Command: Encapsula acciones del jugador en objetos ejecutables.
State: Gestiona los estados del personaje (Idle, Jumping, Attacking).
Observer: Permite que sistemas externos (Audio, Logros) reaccionen a eventos del personaje.

Instrucciones de Compilación y Uso

Clonar el repositorio: git clone <URL_DEL_REPOSITORIO>
Abrir en Visual Studio:
Abrir el archivo Git17979.sln o crear un nuevo proyecto C++ y agregar todos los archivos de la carpeta Source/.
Compilar y ejecutar:
Seleccionar la configuración Debug o Release.
Presionar F5 para ejecutar el proyecto.
Interactuar con el personaje usando las teclas configuradas (w para saltar, f para disparar, etc.).

Command:
El patrón Command encapsula una solicitud como un objeto, permitiendo poner acciones en cola y ejecutarlas de forma independiente. Esto desacopla la entrada del jugador de la lógica de ejecución de acciones.

Código representativo:
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class SaltarCommand : public Command {
public:
    SaltarCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Saltar(); }
private:
    Personaje* personaje_;
};

Uso en el proyecto:
InputHandler recibe la tecla del usuario, busca el comando asociado y llama a execute(). Esto permite cambiar las acciones sin modificar la lógica central.

State:
El patrón State permite que un objeto cambie su comportamiento cuando su estado interno cambia. El personaje se comporta de manera diferente según esté Idle, Jumping o Attacking, sin necesidad de if/else dispersos por todo el código.

Código representativo:
void Personaje::handleInput(char input) {
    switch (currentState_) {
    case State::IDLE:
        if (input == 'w') Saltar();
        else if (input == 'f') Disparar();
        break;
    case State::JUMPING:
        std::cout << "Personaje está en el aire." << std::endl;
        break;
    case State::ATTACKING:
        std::cout << "Personaje está atacando." << std::endl;
        break;
    }
}

Uso en el proyecto:
Personaje mantiene currentState_ y stateCounter_. update() gestiona la transición a Idle cuando finaliza una acción.

Observer:
El patrón Observer define una dependencia uno a muchos, de forma que cuando un objeto cambia de estado, todos sus dependientes son notificados y actualizados automáticamente. Esto es útil para sistemas de Audio o Logros que reaccionan a eventos del personaje.

Código representativo:
class Observer {
public:
    virtual void onNotify(const Personaje& personaje, Evento evento) = 0;
    virtual ~Observer() {}
};

class Logros : public Observer {
public:
    void onNotify(const Personaje& personaje, Evento evento) override {
        if (evento == Evento::PERSONAJE_SALTAR) {
            std::cout << "Desbloqueaste un logro por saltar!\n";
        }
    }
};

Uso en el proyecto:
Personaje mantiene un arreglo de observadores y llama a notify(evento) cada vez que ocurre un evento relevante. Los observadores reaccionan según su lógica interna.

+-------------------+                        +-------------------+
|    Personaje      |------------------------|     Observer      |
+-------------------+                        +-------------------+
| - _health: float  |                        | <<interface>>     |
| - _maxHealth: flt |                        | +onNotify()       |
| - _speed: float   |                        +-------------------+
| - _damage: int    |
| - _jumpheight: flt|
| - currentState_   |
| - stateCounter_   |
| - observadores_[] |
+-------------------+
| +Saltar()         |
| +Disparar()       |
| +Agacharse()      |
| +handleInput()    |
| +update()         |
| +notify()         |
| +agregarObserver()|
+-------------------+
          ^
          |
          |   
+-------------------+      +-------------------+
|      Logros       |      |       Audio       |
+-------------------+      +-------------------+
| - pending_[]      |      | - numPending_     |
+-------------------+      +-------------------+
| +onNotify()       |      | +onNotify()       |
|                   |      | +solicitarSonido()|
|                   |      | +procesarEventos()|
+-------------------+      +-------------------+

+-------------------+                        +-------------------+
|   InputHandler    |------------------------|     Personaje     |
+-------------------+                        +-------------------+
| - saltarCommand_  |                        | - currentState_   |
| - dispararCommand_|                        |                   |
| - agacharseCommand|                        +-------------------+
| - botonArray_[256]|                        | +Saltar()         |
+-------------------+                        | +Disparar()       |
| +handleInput()    |                        | +Agacharse()      |
| +remapearTecla()  |                        +-------------------+
+-------------------+                                  ^
	  ^				     +---------|---------+
	  |				     |      State        | 
	  |				     +-------------------+
	  |				     | IDLE              |
	  |				     | JUMPING           |
	  |				     | ATTACKING         |
	  |				     +-------------------+
+-------------------+
|     Command       | 
+-------------------+
          ^       
          |       
+-------------+ +--------------+ +-----------------+
| SaltarCommand| | DispararCmd | | AgacharseCmd    |
+-------------+ +--------------+ +-----------------+


Con ayuda de chatgpt en la parte de redaccion del README y el formato de los diagramas.
Air Dron Voyage 
#ibrahim
Feature: HU05: Como cliente dudoso quiero hablar con el piloto para que me recomiende lugares de viaje. 

    Scenario: E01: Interactuar con el piloto de drones. 

        Given que me encuentro en el panel de viaje programados 

        When ingrese a "Hablar con el piloto" e ingrese en formato texto mis dudas sobre qué rutas tomar."Se podra viajar hoy a algun lugar cerca de la torre Eiffel"  

        Then el piloto recibirá el mensaje y podrá responder de la misma manera."Si mi estimada, el recorrido que hare hoy dia sera cerca de la torre Eiffel" 

        Examples: 

            | Boton "Hablar con el piloto" | Dudas en formato texto                                         | Se enviara el Mensaje| El piloto enviara mensaje al usuario estresado o persona que solicita|

            | True                         | "Se podra viajar hoy a algun lugar cerca de la torre Eiffel"   | True                  |"Si mi estimada, el recorrido que hare hoy dia sera cerca de la torre Eiffel" |

    Scenario: E02:  Interactuar con el piloto de drones con contenido multimedia. 

        Given que me encuentro en el panel de viajes programados 

        When ingrese a "Hablar con el piloto", añada contenido multimedia con el botón "Abrir multimedia" y presione el botón enviar.  

        Then el piloto recibirá el mensaje multimedia y se enviara un mensaje de confirmacion "se envio tu mensaje multimedia correctamente". 

        Examples: 

           | Boton "Hablar con el piloto" |                Abrir Multimedia            |                    Mensaje                     |  Envio de multimedia|

           |         True                 | se preiona el boton de "abrir multimedia"  | "se envio tu mensaje multimedia correctamente"|  Se envia la foto o video|


Feature: HU06: Como cliente del servicio quiero enviar mis comentarios en formato texto sobre el servicio al piloto para mejorar el servicio. 

    Scenario: E01: Interactuar con el piloto que ya haya dado su servicio en formato texto. 

        Given que me encuentro en el perfil del piloto 

        When  ingrese a la opción "enviar mensaje" 

        And escriba en formato texto un mensaje("Le recomiendo que para proximos viajes pueda ser mas socialble con las personas") y presione el botón enviar. 

        Then  el piloto recibirá un mensaje y recibira feedback. 

        Examples: 

            | Se Presiona boton de enviar mensaje | Mensaje                                                                            |                        Piloto recibe mensaje                         | 

            | True                                | "Le recomiendo que para proximos viajes pueda ser mas socialble con las personas"  |  el piloto recibe el mensaje y de acuerdo a ello mejora su servicio |                                    
  
    Scenario: E02: Interactuar con el piloto que ya haya dado su servicio con contenido multimedia. 

        Given  que me encuentro en el perfil del piloto  

        When  ingrese a la opción "enviar mensaje" 

        And añada el contenido multimedia de con el botón "Abrir multimedia" 

        And presione el botón enviar archivo multimedia ("se envia una grabacion de  voz para agilizar la interaccion").    

        Then se enviara una confirmacion de que el mensaje fue recibido correctamente.("Se envio con exito el envio del archivo multimedia")
        And el piloto recibirá un mensaje y podrá responder de la misma manera. 

 
        Examples: 

            | Opcion Enviar Mensaje | Abrir Multimedia                    | Presione Boton Enviar |             Mensaje de confirmacion                 |  ver el mensaje|

            | Presionada            | Se selecciona un archivo multimedia | Presionada            | Se envio con exito el envio del archivo multimedia | el piloto podra visualizar el mensaje enviado|


Feature: HU07:  Como cliente quiero comentar al piloto en formato texto sobre mis rutas preferidas para un viaje más realista. 

    Scenario:  E01: Interactuar con el piloto de drones en formato texto. 

        Given que me encuentro en el panel de viaje programados  

        When ingrese a "Hablar con el piloto"

        And  ingrese en formato texto la ruta deseada con sus preferencias y presione el botón enviar.Por ejemplo: ("Quisiera primero ir a visitar mas sobre la torre eiffel para luego ir al rio la cena en francia") 

        Then el piloto recibirá el mensaje y podrá responder de la misma manera.por ejemplo("si claro mi estimada iremos como usted indica") 

        Examples: 

            | Boton de Hablar con el piloto |                       Insertar mesanje en formato texto para el piloto                       | Boton de Enviar | Mensaje que enviaria el piloto al usuario    |

            | Presionado                    |Quisiera primero ir a visitar mas sobre la torre eiffel para luego ir al rio la cena en francia |   Presionado  | si claro mi estimada iremos como usted indica|

    Scenario: E02:  Interactuar con el piloto de drones con contenido multimedia.

        Given que me encuentro en el panel de viajes programados

        When ingrese a "Hablar con el piloto", añada el contenido multimedia del lugar de preferencia con el botón "Abrir multimedia" y presione el botón enviar.("enviar fotos o videos de los lugares que quiere ir")

        Then el piloto recibirá el mensaje y podrá responder de la misma manera.(enviar foto del lugar deseado por el usuario)
        And y podra confirmar su paseo de la persona que solicita

        Examples:

             | Boton de Hablar con el piloto | Insertar archivo multimedia                       | Boton de Enviar | enviar archivos devuelta al usuario estresado o persona que solicita|

            | Presionado                     | enviar fotos o videos de los lugares que quiere ir| Presionado    | enviar foto del lugar deseado por el usuario y confirmar su paseo|


Feature: HU08: Como piloto de drones quiero ver los comentarios del cliente estresado para ofrecer un buen servicio. 

    Scenario: E01: Revisar los mensajes de los clientes 

        Given que estoy en mi perfil de piloto de drones  

        When presiono la opción "Mensajes", se abre el panel de mensajes recientes y abra algún mensaje directo. por ejemplo: (*aparecen varios mensajes de diferentes usuarios)
        ("ola me podria dar un paseo virtual por paris porfavor?","me gustaria que la siguiente vez pueda tener varias rutas y que yo elija")

        Then estaré viendo el comentario que me escribió el cliente. (*se podra visualizar los mensajes)

        Examples: 

            | Boton "Mensajes" |                                             Mensajes en la lista                                                                   | El piloto puede ver los mensajes                         | 

            | Presionado       | "ola me podria dar un paseo virtual por paris porfavor?","me gustaria que la siguiente vez pueda tener varias rutas y que yo elija"| el piloto podra visualizar facilmente cada comentario | 

     Scenario: E02: Revisar los mensajes de los clientes cuando no hay ninguno. 

        Given ue estoy en mi perfil de piloto de drones. 

        When presiono la opción "Mensajes", se abre el panel de mensajes recientes, pero no haya ningún mensaje.  

        Then estaré viendo el panel de mensajes vacío y me mostrara un mensaje.("No hay mensajes a mostrar por ahora vuelva pronto!!")

        Examples: 

             | Boton "Mensajes" | Aparecen los mensajes recibidos| El piloto puede ver los mensajes | Mensaje de indicacion de lista de mensajes vacias|

            | Presionado        | False                          | False                            | No hay mensajes a mostrar por ahora vuelva pronto!!|
#ibrahim
#franco
Feature:  HU09: Como cliente recurrente quiero escribir un feedback hacia los pilotos para mejorar su servicio. 

    Scenario: E01: Añadir feedback luego del viaje programado. 

        Given que me encuentro en el panel de "viajes programados"  

        When ingrese a "Valorar servicio" e ingrese en formato de texto un comentario corto. "Me gustaria que me comente mas sobre la ciudad". Seleccione una cantidad de estrellas para el piloto de dron.

        Then se agregará "Me gustaria que me comente mas sobre la ciudad" en la casilla de reseñas del perfil del piloto. 

 
 

        Examples: 

            |Boton "valorar servicio"|                 Comentario Corto                 | Seleccione cantidad de estrellas | Se enviara el mensaje| 

            |True                    | "Me gustaria que me comente mas sobre la ciudad" |  Se selecciona tres estrellas    |        True          | 

 
 
 

    Scenario: E02:  Añadir feedback al entrar al perfil de un piloto que ya haya dado servicio a ese usuario. 

        Given que me encuentro en el panel de "perfil del piloto"   

        When ingrese a "Valorar servicio" e ingrese en formato de texto un comentario corto. "Es mi piloto favorito". Seleccione una cantidad de estrellas para el piloto de dron.

        Then se agregará "Es mi piloto favorito" en la casilla de reseñas del perfil del piloto. 

 
 

        Examples: 

            |Boton "valorar servicio"|    Comentario Corto     | Seleccione cantidad de estrellas  | Se enviara el mensaje| 

            |True                    | "Es mi piloto favorito" |  Se selecciona cinco estrellas    |        True          | 

 
 
 

    Scenario: E03:  Añadir feedback al entrar al historial de viajes. 

        Given que me encuentro en el panel "historial de viajes"  

        When ingrese a un viaje antiguo y seleccione "Valorar viaje" e ingrese en formato de texto un comentario corto. "Me gustaron los panoramas del viaje". Seleccione una cantidad de estrellas para el viaje.

        Then se agregará "Me gustaron los panoramas del viaje" en la casilla de reseñas de viajes. 

 
 

         Examples: 

            | Boton "valorar viaje"  |           Comentario Corto            | Seleccione cantidad de estrellas  | Se enviara el mensaje| 

            |True                    | "Me gustaron los panoramas del viaje" |  Se selecciona cinco estrellas    |        True          | 

 
 
 

    Scenario: E04:  Añadir feedback para el piloto sin especificar la puntuación. 

        Given que me encuentro en el panel de "perfil del piloto"   

        When ingrese a "Valorar servicio" e ingrese en formato de texto un comentario corto. "Me gusta mucho su trabajo". No seleccione una cantidad de estrellas para el piloto de dron.

        Then no se añadirá el feedback.

 
 

         Examples: 

            |Boton "valorar servicio"|      Comentario Corto       | Seleccione cantidad de estrellas  | Se enviara el mensaje| 

            |True                    | "Me gusta mucho su trabajo" |    No se seleccionan estrellas    |        False         | 

 
 
 

    Scenario: E05:  Añadir feedback para el piloto con el comentario vacío. 

        Given que me encuentro en el panel de "perfil del piloto"   

        When ingrese a "Valorar servicio" y no ingrese un comentario. " ". Seleccione una cantidad de estrellas para el piloto de dron.

        Then no se añadirá el feedback. 

 
 

        Examples: 

            |Boton "valorar servicio"|Comentario Corto| Seleccione cantidad de estrellas  | Se enviara el mensaje| 

            |True                    |       " "      |  Se selecciona cuatro estrellas   |        False         | 

 
 
 

    Scenario: E06: Añadir feedback para el piloto sin especificar la puntuación y con el comentario vacío. 

        Given que me encuentro en el panel de "perfil del piloto"   

        When ingrese a "Valorar servicio" y no ingrese un comentario. " ". No seleccione una cantidad de estrellas para el piloto de dron.

        Then no se añadirá el feedback. 

 
 

        Examples: 

            |Boton "valorar servicio"|Comentario Corto| Seleccione cantidad de estrellas  | Se enviara el mensaje| 

            |True                    |       " "      |   No see seleccionan estrellas    |        False         | 

 
 

    Scenario: E07: Salir de añadir feedback para el piloto sin presionar enviar.  

        Given que me encuentro en el panel de "perfil del piloto"   

        When seleccione "Salir". 

        Then aparecerá una ventana con la opción "Descartar mensaje" y regresará al menu principal.

 
 

        Examples: 

            |Boton "Salir"| Boton "Descartar mensaje"| Se regresa al menu principal |

            |True         |         True             |             True             |

Feature: HU10: Como usuario estresado quiero conectar mi celular con la app para usar mi celular como un casco de realidad virtual. 

 
 

    Scenario: E01: Cambiar a vista de realidad virtual para celulares. 

        Given que la transmisión en vivo del viaje ha iniciado

        When  presione "Transformar a vista de realidad virtual para celulares" y conecte el celular.  

        Then  se compartirá la imagen de vídeo con el dispositivo movil y el usuario podrá colocarlo en sus cascos de realidad virtual. 

 
 

        Examples: 

            | Boton "Transformar a vista de realidad virtual para celulares"| Celular conectado | Se compartirá la imagen de vídeo|  

            |                             True                              |      True         |             True                | 

 
 
 

    Scenario: E02: Cambiar a vista de realidad virtual para celulares sin estar con un dispositivo móvil. 

        Given que la transmisión en vivo del viaje ha iniciado  

        When presione "Transformar a vista de realidad virtual para celulares" y no conecte el celular.  

        Then no se compartirá la imagen de vídeo.      

 
 

        Examples: 

            | Boton "Transformar a vista de realidad virtual para celulares" | Celular conectado | Se compartirá la imagen de vídeo| 

            |                          True                                  | False             |           False                 |   

 
 

    Scenario: E03: Volver a cambiar a vista normal. 

        Given  que me encuentro viendo la transmisión en vista de realidad virtual para celulares 

        When presione "Cambiar a vista normal". 

        Then el formato de vídeo se restaurará a su estado original. 

 
 

        Examples: 

            | Boton "Cambiar a vista normal"| Se restaura el formato de video| 

            |             True              |            True                |

Feature: HU11: Como usuario estresado quiero conectar mis cascos de realidad virtual con la app para hacerlo más realista. 

 
 

    Scenario: E01: Cambiar a modo de realidad virtual desde el formato Computadora de escritorio. 

        Given que inicie la transmisión en vivo del viaje

        When  presione "Cambiar a modo de realidad virtual" y conecte mis cascos de realidad virtual a mi computadora.  

        Then el formato de audio se cambiará al de realidad virtual. 

         

        Examples: 

            | Boton "Cambiar a modo de realidad virtual" | Cascos conectados  | Se cambia a realidad virtual| 

            |                   True                     | True               | True                        | 

 
 

    Scenario: E02: Cambiar a modo realidad virtual desde el formato Computadora de escritorio sin haber conectado los cascos de realidad virtual. 

        Given que inicie la transmisión en vivo del viaje

        When  presione "Cambiar a modo de realidad virtual" y no conecte mis cascos de realidad virtual a mi computadora.  

        Then el formato de audio no se cambiará al de realidad virtual. 

         

        Examples: 

            | Boton "Cambiar a modo de realidad virtual" | Cascos conectados  | Se cambia a realidad virtual| 

            |                   True                     | False              | False                       | 

 
 

    Scenario: E03: Cambiar a modo realidad virtual desde el formato Dispositivo móvil 

        Given que inicie la transmisión en vivo del viaje

        When  presione "Cambiar a modo de realidad virtual" y conecte mis cascos de realidad virtual a el dispositivo movil.  

        Then el formato no se cambiará al de realidad virtual porque no es compatible en los dispositivos moviles. 

         

        Examples: 

            | Boton "Cambiar a modo de realidad virtual" | Cascos conectados  | Se cambia a realidad virtual| 

            |                   True                     | True               | False                       |

Feature: HU12: Como piloto de drones quiero ver un registro de viajes para calcular el respectivo cobro a fin de mes. 

 
 

    Scenario: E01: Visualizar el registro de viajes en la aplicación. 

        Given que me encuentro en mi perfil de piloto de drones 

        When  ingrese a "Ver historial de servicios" y seleccione "Ver pago mensual"

        Then el sistema mostrará todos los viajes realizados junto con los pagos mensuales. 


 

        Examples: 

            |      Boton "Ver historial de servicios"      |Boton "Ver pago mensual" | Se mostrarán los viajes y pagos | 

            |                     True                     | True                    | True                            | 

 
 

    Scenario: E02: Visualizar el registro de viajes en la aplicación siendo piloto nuevo. 

        Given que me encuentro en mi perfil de piloto de drones 

        When ingrese a la opción "Ver historial de servicios". 

        Then el sistema mostrará el panel del registro de los viajes. 

 
 

        Examples: 

            |     Boton "Ver historial de servicios"        | Se mostrará el registro de viajes  |

            |                      True                     | True                               |
#franco
#alejandro
Feature: HU13: Como piloto de drones quiero ver un historial del tiempo de servicio en la app para cobrar por ese tiempo. 

 
 

    Scenario: E01: Visualizar el tiempo de servicio en la aplicación. 

        Given que me encuentro en mi perfil de piloto de drones 

        When ingrese a la opción "Ver tiempo en servicio". 

        Then el sistema mostrará cada viaje realizado por el piloto con su respectivo tiempo de viaje y en la parte inferior mostrando la cantidad de que puede cobrar de acuerdo al tiempo y, a su vez, en la parte superior mostrará el tiempo total de servicio dentro de la aplicación. 

 
 

        Examples: 

            | Presionar Boton de "Ver tiempo en servicio"                | Perfil de piloto de drones   | Visualizar tiempo de servicio  | Detalles del piloto | 

            | Presionando                                                | True                         | True                           | True                | 

 
 

    Scenario: E02: Visualizar el tiempo de servicio en la aplicación siendo piloto nuevo. 

        Given que me encuentro en mi perfil de piloto de drones 

        When  ingrese a la opción "Ver tiempo en servicio". 

        Then el sistema me mostrará un panel de viajes vacío debido a que soy piloto nuevo. 

 
 

        Examples: 

            | Presionar Boton de "Ver tiempo en servicio"               | Perfil de piloto de drones   | Visualizar tiempo de servicio  | Detalles del piloto  | 

            | Presionando                                               | True                         | True                           | False                | 
  
Feature: HU14: Como piloto quiero ver notificaciones de la batería del dron para no preocuparme por este. 

 
 

    Scenario: E01: Notificaciones sobre la batería del dron. 

        Given que me encuentro en pleno vuelo de dron 

        When mi dron se quede con 50% de batería. 

        Then me aparecerá a un lado de la pantalla principal una notificación sobre la batería de este. 

 
 

        Examples: 

            | Presionar Notificaciones de la batería del dron         |  En vuelo de dron   |  Cantidad de bateria   | Notificaciones de la batería a un lado de la pantalla principal | 

            | Presionando                                             | True                | True                   | True                                                            | 

 
 

        Given que me encuentro en pleno vuelo de dron 

        When mi dron se quede con 25% de batería. 

        Then me aparecerá a un lado de la pantalla principal una notificación sobre la batería de este. 

 
 

        Examples: 

            | Presionar Notificaciones de la batería del dron         |  En vuelo de dron   |  Cantidad de bateria   | Notificaciones de la batería a un lado de la pantalla principal | 

            | Presionando                                             | True                | True                   | True                                                            | 

 
 

        Given que me encuentro en pleno vuelo de dron 

        When mi dron se quede con 20% de batería. 

        Then me aparecerá a un lado de la pantalla principal una notificación sobre la batería de este. 

 
 

        Examples: 

            | Presionar Notificaciones de la batería del dron         |  En vuelo de dron   |  Cantidad de bateria   | Notificaciones de la batería a un lado de la pantalla principal | 

            | Presionando                                             | True                | True                   | True                                                            | 

 
 

        Given que me encuentro en pleno vuelo de dron 

        When mi dron se quede con menos del 20% de batería. 

        Then me seguirá notificando hasta que quede a 15% con un mensaje de advertencia. 

 
 

        Examples: 

            | Presionar Notificaciones de la batería del dron         |  En vuelo de dron   |  Cantidad de bateria   | Mensaje de advertencia de la bateria | 

            | Presionando                                             | True                | True                   | True                                 | 

         

        Given que me encuentro en pleno vuelo de dron 

        When mi dron se quede con 15% de batería. 

        Then me aparecerá a un lado de la pantalla principal una notificación sobre la batería de este y automáticamente el dron tendrá que bajar. 

 
 

        Examples: 

            | Presionar Notificaciones de la batería del dron         |  En vuelo de dron   |  Cantidad de bateria   | Notificacion del dron y dron de bajada | 

            | Presionando                                             | True                | True                   | True                                   | 


Feature: HU15: Como cliente estresado quiero ver la localización del dron en un pequeño mapa para guiarme en la ciudad. 

 
 

    Scenario: E01: Abrir la locación del dron en la transmisión. 

        Given que la transmisión en vivo del dron ha iniciado 

        When seleccione el icono del mapa que esta arriba a la izquierda. 

        Then se abrirá un mapa con la localización en tiempo real del dron en la ciudad. 

 
 

        Examples: 

            | Presionar Boton de "Ver mapa"                   | Boton de ver mapa   | Mapa en tiempo real | 

            | Presionando                                     | True                | True                |  

     

    Scenario: E02:  Abrir la locación del dron en otro dispositivo. 

        Given que la transmisión en vivo del dron ha iniciado 

        When  ingrese en un dispositivo diferente, seleccione el viaje en transcurso, aparecen dos botones "Ver transmisión aquí" o "Ver mapa" y selecciono el segundo botón. 

        Then se abrirá un mapa con la locación en tiempo real del dron en la ciudad desde un dispositivo diferente. 

 
 

        Examples: 

            | Presionar Boton de "Ver mapa"                  | Boton de ver mapa   | Mapa en tiempo real desde un dispositivo diferente | 

            | Presionando                                    | True                | True                                               | 


Feature: HU16: Como piloto de drones quiero visualizar la locación del dron en pleno vuelo para evitar accidentes. 

     

    Scenario: E01: Abrir y ver la locación del dron en un mapa con la aplicación del dron vinculada. 

        Given que he vinculado la aplicación del dron con la aplicación AirDronVoyage 

        When comience la transmisión en vivo y seleccione el botón mapa.  

        Then se abrirá el mapa en tiempo real de la ubicación del dron usando el GPS del mismo. 

 
 

        Examples: 

            | Presionar Boton de "Ver mapa"         | Vincular aplicacion de dron con aplicacion de AirDronVoyage   | Boton de mapa    | Ubicacion de dron en GPS |   

            | Presionando                           | True                                                          | True             | True                     | 

         

    Scenario: E02: Abrir y ver la locación del dron en un mapa sin la aplicación del dron vinculada. 

        Given no he vinculado la aplicación del dron con la aplicación AirDronVoyage 

        When comience la transmisión en vivo y seleccione el botón mapa. 

        Then aparecerá un enlace para vincular las aplicaciones junto con un mensaje de error indicando que se necesita vincular para usar el mapa. 

 
 

        Examples: 

            | Presionar Boton de "Ver mapa"         | Vincular aplicacion de dron con aplicacion de AirDronVoyage   | Boton de "Ver mapa" | Ubicacion de dron en GPS | 

            | Presionando                           | False                                                         | True                | False                    | 
#alejandro

#allison
Feature: HU17: Como piloto quiero ver en vivo la cámara del dron para asegurar que el usuario disfrute de las mejores vistas. 

     

    Scenario: E01: Ver en directo la cámara del dron a través de la app en el celular. 

        Given que estoy realizando un viaje virtual para un usuario estresado 

        When vea la pantalla principal y presione el botón "Ver transmisión aquí". 

        Then estaré viendo en vivo la cámara de mi dron a través de la app en el celular y además me llegará un mensaje en la pantalla que dice "el viaje virtual ha comenzado". 

 
 

        Examples: 

            | Presionar Boton de "Ver transmisión aquí"   | Viaje virtual   | Pantalla principal  | visualizar transmisión de el dron en celular | mensaje en la pantalla al piloto|

            | Presionando                                 | True            | True                | True                                         | "El viaje virtual ha comenzado"|

         

    Scenario: E02: Ver en directo la cámara del dron a través de una computadora. 

        Given que estoy realizando un viaje virtual para un usuario estresado 

        When vea la pantalla principal y seleccione el boton "Ver transmisión aquí" . 

        Then estaré viendo en vivo la cámara de mi dron desde una computadora y además me llegará un mensaje en la pantalla que dice "el viaje virtual ha comenzado". 

 
 

        Examples: 

            | Presionar Boton de "Ver transmisión aquí"   | Viaje virtual   | Pantalla principal  | visualizar transmisión de el dron en computadora | mensaje en la pantalla al piloto|

            | Presionando                                 | True            | True                | True                                             | "El viaje virtual ha comenzado"|

Feature: HU18: Como cliente estresado quiero ver en vivo la ciudad visitada para desestresarme y relajarme. 

     

    Scenario: E01: Ingresar a la transmisión del dron. 

        Given que es la hora programada para el viaje y me aparece un aviso que dice "En breve comienza la transmisión del dron" 

        When le doy al botón "Comenzar viaje". 

        Then se abrirá la transmisión en vivo con la cámara del dron en vuelo y además me llegará un mensaje en la pantalla que dirá "el viaje virtual ha comenzado". 

 
 

        Examples: 

            | Presionar Boton "comenzar viaje"    | Hora del viaje programado   | Boton comenzar viaje    | Transmision del vuelo  | mensaje en la pantalla al usuario|

            | Presionando                         | True                        | True                    | True                   | "El viaje virtual ha comenzado"| 

         

    Scenario: E02: Cambiar de dispositivo para ver la transmisión. 

        Given que la transmisión del viaje ha iniciado y me aparece un aviso que dice "En breve comienza la transmisión del dron" 

        When ingrese en otro dispositivo, seleccione el viaje en transcurso y elija la opción "Ver la transmisión aquí". 

        Then se abrirá la transmisión en vivo en el nuevo dispositivo con la cámara del dron en vuelo y además me llegará un mensaje en la pantalla que dirá "ha cambiado de dispositivo correctamente"

 
 

        Examples: 

            | Presionar Boton "comenzar viaje "   | Viaje iniciado      | Ver transmisión aqui   | Transmision del dron  | mensaje en la pantalla al usuario|

            | Presionando                         | True                | True                   | True                  | "Ha cambiado de dispositivo correctamente"|

Feature: HU19: Como persona que requiere desestresarse quiero ver en alta resolución el paseo virtual para desestresarme con el paisaje. 

     

    Scenario: E01: Cambiar la calidad de la transmisión en vivo. 

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 144p. 

        Then la calidad del vídeo cambiará a la 144p y saldrá un aviso en la pantalla que dice "Cambiado a 144p". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 144p | Mensaje en la pantalla del usuario  |
            | Presionando                                     | True                              | True                                        | "Cambiado a 144p"|

         

     

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 240p. 

        Then la calidad del vídeo cambiará a la 240p y saldrá un aviso en la pantalla que dice "Cambiado a 240p". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 240p | Mensaje en la pantalla del usuario  |

            | Presionando                                     | True                              | True                                        | "Cambiado a 240p"|

         

        Given  Dado que me encuentro en la transmisión en vivo de la cámara del dron  

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 360p 

        Then la calidad del vídeo cambiará a la 360p y saldrá un aviso en la pantalla que dice "Cambiado a 360p". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 360p | Mensaje en la pantalla del usuario  |

            | Presionando                                     | True                              | True                                        | "Cambiado a 360p"|

         

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 480p. 

        Then la calidad del vídeo cambiará a la 480p y saldrá un aviso en la pantalla que dice "Cambiado a 480p". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 480p | Mensaje en la pantalla del usuario  |

            | Presionando                                     | True                              | True                                        | "Cambiado a 480p"|

         

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 720p. 

        Then  la calidad del vídeo cambiará a la 720p y saldrá un aviso en la pantalla que dice "Cambiado a 720p". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 720p | Mensaje en la pantalla del usuario   |

            | Presionando                                     | True                              | True                                        | "Cambiado a 720p"|

         

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 1080(HD). 

        Then  la calidad del vídeo cambiará a la 1080(HD) y saldrá un aviso en la pantalla que dice "Cambiado a 1080(HD)". 

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 1080(HD) | Mensaje en la pantalla del usuario | 

            | Presionando                                     | True                              | True                                            | "Cambiado a 1080(HD)"|

         

        Given que me encuentro en la transmisión en vivo de la cámara del dron 

        When presione el botón de la esquina a la derecha con un engranaje y elijo la calidad 2160(4K). 

        Then  la calidad del vídeo cambiará a la 2160(4K) y saldrá un aviso en la pantalla que dice "Cambiado a 2160(4K)".  

 
 

        Examples: 

            | Presionar Boton de "calidad de la transmisión"  | Boton de calidad de la transmisión| Cambiar la calidad de la transmisión a 2160(4k) | Mensaje en la pantalla del usuario  |

            | Presionando                                     | True                              | True                                            | "Cambiado a 2160(4K)" |

Feature: HU20: Como usuario estresado quiero un buscador para buscar mis lugares favoritos de viaje. 

     

    Scenario: E01: Buscar viajes disponibles dentro del catálogo. 

        Given que me encuentro en el menú de la aplicación 

        When seleccione "Catálogo de lugares turísticos", seleccione el icono de lupa que se encuentra arriba a la derecha de la pantalla, ingrese en formato texto el lugar deseado y presione el botón buscar. 

        Then cargará una página nueva con los lugares turísticos relacionados a ese texto ingresado. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"  | Menu de la aplicacion  | Boton de buscar en forma de lupa  | Lugares turisticos de acuerdo al texto | 

            | Presionando                                          | True                   | True                              | True                                   | 

         

    Scenario: E02: Buscar viajes disponibles dentro del catálogo sin llenar la casilla de búsqueda. 

        Given que me encuentro en el menú de la aplicación 

        When seleccione "Catálogo de lugares turísticos", seleccione el icono de lupa que se encuentra arriba a la derecha de la pantalla, no ingrese ningún texto y presione el botón buscar. 

        Then el sistema no realizará ninguna búsqueda cambiando el color de la lupa a rojo.

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"  | Menu de la aplicacion  | Sin texto   | Lugares turisticos de acuerdo al texto | 

            | Presionando                                          | True                   | True        | False                                  | 

 
 

     Scenario: E03: Buscar viajes disponibles dentro del catálogo y rellenar la casilla de búsqueda con datos erróneos. 

        Given  que me encuentro en el menú de la aplicación 

        When  seleccione "Catálogo de lugares turísticos", seleccione el icono de lupa que se encuentra arriba a la derecha de la pantalla, ingrese en formato texto un lugar que no existe y presione el botón buscar. 

        Then cargará una página en blanco diciendo que no existe el lugar indicado y debajo aparecerá una lista de otras recomendaciones de viajes. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"  | Menu de la aplicacion  | Texto no existente  | Lugares turisticos de acuerdo al texto | Otras recomendaciones de viajes|

            | Presionando                                          | True                   | True                | False                                  | True|

 
 

     Scenario: E04: Buscar viajes no disponibles dentro del catálogo. 

        Given que me encuentro en el menú de la aplicación 

        When  seleccione "Catálogo de lugares turísticos", seleccione el icono de lupa que se encuentra arriba a la derecha de la pantalla, ingrese en formato texto un lugar que no está disponible y presione el botón buscar 

        Then cargará una página con un mensaje indicando que no esta disponible ese destino y debajo aparecerá una lista de otras recomendaciones de viajes. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"  | Menu de la aplicacion  | Lugar turístico existente | Disponibilidad del viaje buscado       | Otras recomendaciones de viaje|

            | Presionando                                          | True                   | True                      | False                                  | True|
#allison
#kamila
Feature: HU21: Como adulto estresado quiero visualizar un catálogo de lugares para escoger mis lugares favoritos. 

     

    Scenario: E01: Ingresar al catálogo de viajes siendo usuario nuevo. 

        Given que me encuentro en el menú de la aplicación 

        When  seleccione "Catálogo de lugares turísticos". 

        Then cargará una página nueva con lugares turísticos disponibles para el cliente. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"    | Menu de la aplicacion | Boton de catalogo de lugares turiticos | lugares turiticos disponibles |  

            | Presionando                                        | Menu                 |     Canada                               | Destino disponible                        | 

         

    Scenario: E02: Buscar recomendaciones según pilotos. 

        Given que me encuentro en el menú de la aplicación 

        When seleccione "Catálogo de lugares turísticos" y elija la opción "Lugares recomendados por pilotos". 

        Then cargará una página nueva con lugares turísticos recomendados por pilotos. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"    | Menu de la aplicacion | Boton de catalogo de lugares turiticos | Boton de lugares recomendados por el piloto | Lugares turisticos recomendados | 

            | Presionando                                            | Menu                  | Canada                                   | Recomendacion del piloto                                        | EEUU y mexico                            | 

Feature: HU22: Como joven que busca nuevas experiencias quiero que la app me recomiende lugares de acuerdo con mis gustos para disfrutar más viajes. 

     

    Scenario: E01: Ingresar al catálogo de viajes siendo usuario veterano. 

        Given que me encuentro en el menú de la aplicación 

        When seleccione "Catálogo de lugares turísticos". 

        Then el sistema que detecta a un usuario veterano, según su historial de viajes, cargará una página nueva con lugares turísticos recomendados por la aplicación disponibles para el usuario. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"    | Menu de la aplicacion | Boton de catalogo de lugares turiticos | lugares turiticos disponibles para veteranos |  

            | Presionando                                            | Menu                 | Distintos lugares turisticos                                   | Roma                                          | 

         

    Scenario: E02:  Buscar recomendaciones según pilotos. 

        Given  que me encuentro en el menú de la aplicación 

        When seleccione "Catálogo de lugares turísticos" y elija la opción "Lugares recomendados por pilotos". 

        Then cargará una página nueva con lugares turísticos recomendados por pilotos que hayan ofrecido un viaje a ese cliente. 

 
 

        Examples: 

            | Presionar Boton de "Catalogo de lugares turisticos"    | Menu de la aplicacion | Boton de catalogo de lugares turiticos | Boton de lugares recomendados por el piloto | Lugares recomendados  | 

            | Presionando                                            | Menu                 | Canada                                   | EEUU y mexico                                       | Brasil                  | 

Feature: HU23: Como cliente nuevo quiero obtener una prueba gratuita para disfrutar mi paseo sin anuncios. 

     

    Scenario: E01: Buscar la prueba gratuita del servicio. 

        Given que ya estoy registrado en la aplicación 

        When abro el botón "Premium". 

        Then la aplicación muestra un menú para ser "Suscriptor Premium" conteniendo las opciones de pago "Prueba gratuita", "Suscripción de 1 mes" y "Suscripción de 3 meses" ordenadas de forma vertical por costo. 

 
 

        Examples: 

            | Presionar Boton "Premium"  | Registro a la plicacion | Boton de premium | Boton de pago    |  

            | Presionando                | Jose@fdwafwa.com                 | Activar cuenta premium            | visa o mastercard            | 

         

    Scenario: E02: Obtener la prueba gratuita. 

        Given que me encuentro en el formulario para obtener la prueba gratuita 

        When le doy a comenzar, selecciono método de pago, lleno los datos de la tarjeta, confirmo la contraseña de la cuenta y selecciono el botón enviar. 

        Then puedo disfrutar de los beneficios de la app con la prueba gratuita y puede cancelar el servicio cuando la fecha límite para la prueba se acerque. 

 
 

        Examples: 

            | Presionar Boton "Premium"  | Registro a la plicacion | Boton de premium | Boton de pago       | Boton prueba gratuita  | 

            | Presionando                | Jose@fdwafwa.com                  | Activar cuenta premium           | visa o mastercard              | 1 mes de prueba gratis                  | 

 
 

    Scenario: E03:  Dejar casillas en blanco en el formulario de prueba gratuita. 

        Given que me encuentro en el formulario para obtener la prueba gratuita 

        When le doy a comenzar, selecciono método de pago, dejo casillas en blanco, confirmo la contraseña de la cuenta y selecciono el botón enviar. 

        Then me aparecerá un mensaje indicando que deben rellenarse todos los campos. 

 
 

        Examples: 

            | Presionar Boton de "Prueba gratuita" |  Formulario | Metodo de pago | boton enviar    | Rellene campos vacios | 

            | Presionando                          |  Vacio     | Vacio         | Enviando formulario           | Rellenar los  campos campos vacios                | 

 
 

    Scenario: E04: No seleccionar método de pago en el formulario de prueba gratuita. 

        Given que me encuentro en el formulario para obtener la prueba gratuita 

        When le doy a comenzar, no selecciono método de pago y selecciono el botón siguiente. 

        Then  me aparecerá un mensaje indicando que debe elegirse un método de pago. 

 
 

        Examples: 

            | Presionar Boton de "Prueba gratuita" |  Formulario | Metodo de pago | boton enviar    | Rellene campos vacios | 

            | Presionando                          |    Jose@fdwafwa.com      | No seleccionado          | Envir formulario           | Elija un metodo de pago                 | 

 
 

    Scenario: E05: Ingresar una contraseña incorrecta en el formulario de prueba gratuita. 

        Given que me encuentro en el formulario para obtener la prueba gratuita 

        When  le doy a comenzar, selecciono método de pago, lleno los datos de la tarjeta, ingreso una contraseña incorrecta y presiono el botón siguiente.  

        Then me aparecerá un mensaje indicando que la contraseña no coincide. 

 
 

        Examples: 

            | Presionar Boton de "Prueba gratuita" |  Formulario | Metodo de pago | Contraseña | boton enviar    | Rellene campos vacios | 

            | Presionando                          |  Jose@fdwafwa.com        | visa           | fawfe12      | Enviar formulario           | Contraseña incorrecta                 | 
#kamila
#ibrahim
Feature: HU24: Como joven estresado quiero disfrutar los viajes con la implementación de realidad aumentada para sentir más realista el viaje. 

    Scenario: E01: Presiono Realidad Aumentada y en mi tipo de celular está disponible.

        Given  que me encuentro disfrutando de un paseo virtual, pero no entiendo el idioma 

        When seleccione "Traductor Realidad Aumentada" y está disponible en mí celular.

        Then el sistema automáticamente me mostrara la version de las letras en mi idioma y entenderé este.
        
        And me mostrara un mensaje de confirmacion  "SE ESTA ACTIVANDO EL TRADUCTOR DE REALIDAD AUMENTADA" 
 

        Examples: 

            | Presionar Boton "Traductor Realidad Aumentada"  | Esta Disponible en mi celular    | MENSAJE                                              | 

            | Presionando                                    | True                              | SE ESTA ACTIVANDO EL TRADUCTOR DE REALIDAD AUMENTADA |     

    Scenario: E02: Presiono Realidad Aumentada y en mi tipo de celular no está disponible.
        Given   que me encuentro disfrutando de un paseo virtual, pero no entiendo el idioma

        When seleccione "Traductor Realidad Aumentada" y no está disponible. 

        Then  el sistema me mostrara un mensaje diciéndome que no se puede realizar dicha acción."NO ESTA DISPONIBLE EN TU TIPO DE CELULAR"

               Examples: 

            | Presionar Boton "Traductor Realidad Aumentada"  | Esta Disponible en mi celular      | MENSAJE                                              | 

            | Presionando                                    | FALSE                              | NO ESTA DISPONIBLE EN TU TIPO DE CELULAR |     




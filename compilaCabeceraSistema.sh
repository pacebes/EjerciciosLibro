#/bin/bash

export DEPURACION="NO"

export COMANDO_COMPILACION="g++ -std=c++20 -fmodules-ts -xc++-system-header "

export FICHERO_TEMPORAL=""


function mensajeError
{
  echo "$*" >&2
}

function mensajeStd
{
  echo "$*" >&1
}

function mensajeFichero
{
  echo "$*" >> ${FICHERO_TEMPORAL} 2>&1
}

if [ ${DEPURACION} = "SI" ]
then
  BASE_TEMPORAL=`basename $0`
  FICHERO_TEMPORAL=`mktemp -q /tmp/${BASE_TEMPORAL}.XXXXXX`

  echo "${PWD} e invocado con ${#} parametros " >> ${FICHERO_TEMPORAL}
  
  if [ $? -ne 0 ]; then
    mensajeError "$0: No puedo crear el fichero temporal, adios ..."
    exit 1
  fi
fi

if [ $# -gt 0 ]
then
  for i in ${*}
  do
    #
    # compilamos la librería
    #
    export COMANDO="${COMANDO_COMPILACION} ${i}"

    export RESULTADO=`echo $(eval ${COMANDO})`

    if [ ${DEPURACION} = "SI" ]
    then
      mensajeFichero "Comando " ${COMANDO}
      mensajeFichero "Resultado: " ${RESULTADO}
    fi


  done
  
else
    if [ ${DEPURACION} = "SI" ]
    then
      mensajeFichero "Error: no se ha recibido ningún parámetro de entrada desde ${PWD}"
    fi
fi


if [ ${DEPURACION} = "SI" ]
then
  echo "Fichero temporal: " ${FICHERO_TEMPORAL} >&2
  cat ${FICHERO_TEMPORAL}
  rm ${FICHERO_TEMPORAL}
fi

mensajeStd "Compilados los modulos ${*}" 


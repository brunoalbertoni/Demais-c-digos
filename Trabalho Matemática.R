funcao_mmc_mdc_fat <- function() {
  print("Digite dois ou três valores para os cálculos.")
  print("OBS: se desejar inserir apenas dois valores, digite 0 para o terceiro valor.")
  x <- as.numeric(readline("1°: "))
  y <- as.numeric(readline("2°: "))
  z <- as.numeric(readline("3°: "))
  a <- x
  b <- y
  c <- z
  if (a > b) {
    temp <- a
    a <- b
    b <- temp
  }
  if (c == 0) {
    c <- b
  }
  if (b > c) {
    temp <- b
    b <- c
    c <- temp
  }
  if(a>b){
    temp<-a
    a<-b
    b<-temp
  }
  mmc <- a
  while ((mmc %% b) | (mmc %% c)) {
    mmc <- mmc + a
  }
  r <- 1
  while (r != 0) {
    r <-  b %% a
    b <- a
    a <- r
  }
  r <- 1
  while (r != 0) {
    r <-  c %% b
    c <- b
    b <- r
  }
  mdc <- c
  if(z == 0){
    print(paste("MDC: ", mdc))
    print(paste("MMC: ", mmc))
  }else{
    print(paste("MDC dos números: ", mdc))
    print(paste("MMC dos números: ", mmc))
  }
  lista_fatores<-c()
    div<-3
    while (x%%2==0){
      lista_fatores<-append(lista_fatores,2)
      x<-x/2
    }
    while (div^2<=x){
      if (x%%div==0){
        lista_fatores<-append(lista_fatores,div)
        x<-x/div
      }else{
        div<-div+2
      }
    }
    if (x>1) {
      lista_fatores<-append(lista_fatores,x)
    }
  print(paste("São os fatores primos do primeiro número:"))
  print(lista_fatores)

  lista_fatores<-c()
  div<-3
  while (y%%2==0){
    lista_fatores<-append(lista_fatores,2)
    y<-y/2
  }
  while (div^2<=y){
    if (y%%div==0){
      lista_fatores<-append(lista_fatores,div)
      y<-y/div
    }else{
      div<-div+2
    }
  }
  if (y>1) {
    lista_fatores<-append(lista_fatores,y)
  }
  print(paste("São os fatores primos do segundo número:"))
  print(lista_fatores)

  if (z!=0){
  lista_fatores<-c()
  div<-3
  while (z%%2==0){
    lista_fatores<-append(lista_fatores,2)
    z<-z/2
  }
  while (div^2<=z){
    if (z%%div==0){
      lista_fatores<-append(lista_fatores,div)
      z<-z/div
    }else{
      div<-div+2
    }
  }
  if (z>1) {
    lista_fatores<-append(lista_fatores,z)
  }
  print(paste("São os fatores primos do terceiro número:"))
  print(lista_fatores)
  }else{
    print(paste("Não há terceiro número!"))
  }
}

#Para executar a função -> funcao_mmc_mdc_fat no console

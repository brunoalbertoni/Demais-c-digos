import customtkinter as ctk
import pyodbc
import re



dsn= 'MySQL_Workbench'
user= 'root'
password='coxamarilia10'


dados_conexao = f'DSN={dsn};UID={user};PWD={password}'
conexao=pyodbc.connect(dados_conexao)
print('Conexao bem sucedida')

cursor= conexao.cursor()

ctk.set_appearance_mode('dark')
ctk.set_default_color_theme('dark-blue')

janela=ctk.CTk()
janela.geometry('500x300')

texto = ctk.CTkLabel(janela, text='Fazer Login')
texto.place(x=75,y=20)

def botao_login():
    email=entry_email.get()
    senha=entry_senha.get()
    comando = f"""SELECT * FROM login WHERE email='{email}'"""
    cursor.execute(comando)
    resultado=cursor.fetchone()
    if resultado:
        if resultado[1]== senha:
            janela2=ctk.CTkToplevel()
            janela2.geometry('500x250')
            janela2.mainloop
            texto=ctk.CTkLabel(janela2,text='LOGIN FEITO COM SUCESSO!')
            texto.pack(padx=10,pady=10)
            
        else:
            texto2=ctk.CTkLabel(janela, text='Senha incorreta')
            texto2.place(x=50,y=210)
    else:
        texto2=ctk.CTkLabel(janela, text='Informações incorretas')
        texto2.place(x=50,y=210)
    
    


entry_email=ctk.CTkEntry(janela, placeholder_text='Insira seu e-mail')
entry_email.place(x=47,y=70)

entry_senha=ctk.CTkEntry(janela, placeholder_text='Insira sua senha',show='*')
entry_senha.place(x=47,y=120)





def cadastrar():
    email=entry_email2.get()
    padrao = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    email_f=re.match(padrao, email) 
    if email_f==None:
        
        texto=ctk.CTkLabel(janela,text='Digite um e-mail válido')
        texto.place(x=300,y=210)
        email_f=re.match(padrao, email)
    senha=entry_senha2.get()
    
    if email_f!=None:
        comando = f'''INSERT INTO login(email,senha)
        VALUES
        ('{email}','{senha}')'''
        cursor.execute(comando)
        cursor.commit( )
        texto2=ctk.CTkLabel(janela,text='Cadastro Realizado')
        texto2.place(x=315,y=210)
        
botao=ctk.CTkButton(janela,text='Login',command=botao_login)
botao.place(x=47,y=170)  
    
texto=ctk.CTkLabel(janela,text='Não tem login? Faça seu cadastro')
texto.place(x=275,y=20)
entry_email2=ctk.CTkEntry(janela, placeholder_text='Insira seu e-mail')
entry_email2.place(x=297,y=70)
entry_senha2=ctk.CTkEntry(janela, placeholder_text='Insira sua senha',show='*')
entry_senha2.place(x=297,y=120)
botao=ctk.CTkButton(janela,text='Cadastre-se',command=cadastrar)
botao.place(x=297,y=170)

def limpar_lista():
    comando= "DELETE FROM login"
    cursor.execute(comando)
    cursor.commit()
botao=ctk.CTkButton(janela,text='Limpar cadastros',command=limpar_lista)
botao.place(x=175,y=250)
    
janela.mainloop()

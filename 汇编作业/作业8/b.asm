.model tiny
.stack
.data
	string1 db 'please input:',0dh,0ah,'$'
	fName db 'd:\data.txt',0h
	buffer db 81
	db 0
	db 81 dup(0)
.code
.startup
	mov dx,offset string1
	mov ah,09h
	int 21h
	mov dx,offset buffer
	mov ah,0ah
	int 21h

	mov dx,offset fName ; �����ļ�
	mov cx,0
	mov ah,3ch
	int 21h 

	mov ah,3dh          ;���ļ�
    mov al,03
    mov dx,offset fName
    int 21h
    push ax             ;�����ļ����

    mov bx,ax
    mov cx, 12
    lea dx,buffer+2
    mov ah,40h
    int 21h             ;д�ļ�

    pop bx              ;�����ļ����

    mov ah,3eh          ;�ر��ļ�
    int 21h

.exit 0
end
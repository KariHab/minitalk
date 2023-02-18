/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/17 21:16:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*le fichier exe doit se nommer server
doit etre lance en premier et afficher son PID
il doit recevoir le str envoye par le clien et l'afficher (ft_printf)
peut recevoir plusieurs str de plusieurs clients sans devoir etre relance
confirme la reception en envoyant un signal au client 
fonctions:
kill() envoi un signal a un process via son PID
get pid pour avoir le pid du client 

Pseudocode:
affiche son pid
recevoir un str
printer la str
get the pid du client
envoi un signal pour confirmer la reception du signal 
si reception d'un autre signal, pause celui en cours et traiter le signal en question
*/


#include "minitalk.h"

void    ft_bintoa(int sig_num)
{
    static int  bit;
    static int index;
    
    if (sig_num == SIGUSR1)
        index |=(0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", index);
        bit = 0; 
        index = 0;
    }
}



int main(int ac, char **av)
{
    pid_t server_pid;
    
    server_pid = getpid();
    ft_printf("%d\n", server_pid);
    while (ac == 1)
    {
        signal(SIGUSR1, ft_bintoa);
        signal(SIGUSR2, ft_bintoa);
        pause ();
    }
    if (ac != 1)
    {
        ft_printf("Error\n");
        retunr (1);
    }
    return (0);
}
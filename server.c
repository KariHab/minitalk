/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/16 20:02:35 by khabbout         ###   ########.fr       */
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


static void signal_user(int signal_nb)
{
    if (signal_nb == SIGUSR1)
        printf("SIGURS1 received\n");
    else if (signal_nb == SIGUSR2)
        printf("SIGUSR2 received\n");
}


int main(void)
{
    pid_t server_pid;
    
    printf("%d", server_pid = getpid());
    signal(SIGUSR1, signal_user);
}
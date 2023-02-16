/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/16 15:15:40 by khabbout         ###   ########.fr       */
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
si reception d' un autre signal, pause celui en cours et traiter le signal en question
*/
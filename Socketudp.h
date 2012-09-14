#ifndef SOCKETUDP_H
#define SOCKETUDP_H


/*
 * File:   CommunicationUDP.h
 * Author: Arnaud Valensi
 *
 * Created on 11 mars 2011, 14:09
 * Desc:    classe de gestion de communication (socket)
 */

#include "Socketudp.h"
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

#define DEBUG

class CommunicationUDP
{

public:
  //CommunicationUDP();
  CommunicationUDP(std::string ipDestination, int portDestination);
  ~CommunicationUDP();
  int envoyer(std::string datagramme);
  int recevoir();

  int ouvrir();
  int fermer();

private:
  //std::string datagramme;
  int descripteurSocketUDP;
  udp::endpoint *receiver_endpoint;
  udp::endpoint *sender_endpoint;
  udp::socket *socket;


  //io_service permet d'acceder aux fonctionnalité I/O de la librairie asio
  boost::asio::io_service io_service;


};

#endif // SOCKETUDP_H

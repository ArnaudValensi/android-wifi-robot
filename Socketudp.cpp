/*
 * File:   CommunicationUDP.cpp
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
using namespace std;

CommunicationUDP::CommunicationUDP(string ipDestination, int portDestination)
{

   #ifdef DEBUG
   std::cout << "Debut\n";
   cout << "ip : " << ipDestination << ", port : " << portDestination << endl;
   #endif

   try
   {
      //creation des endpoint
      receiver_endpoint = new udp::endpoint(boost::asio::ip::address::from_string(ipDestination), portDestination);
      sender_endpoint  = new udp::endpoint();

      //creation du socket UDP
      socket = new udp::socket(io_service);
   }
   catch (std::exception& e)
   {
      std::cerr << "Standard exception: " << e.what() << std::endl;
      //throw ExceptionApplication(e.what(), __LINE__ );
   }
}


CommunicationUDP::~CommunicationUDP()
{
      delete receiver_endpoint;
      delete sender_endpoint;
      delete socket;
}


int CommunicationUDP::ouvrir()
{
   try
   {
      socket->open(udp::v4());

      #ifdef DEBUG
      std::cout << "open\n";
      #endif

      if(socket->is_open())
            return 0;
      else	return 1;
   }
   catch (std::exception& e)
   {
      std::cerr << "Standard exception: " << e.what() << std::endl;
      throw;
   }
}


int CommunicationUDP::envoyer(std::string datagramme)
{
   size_t nb;

   if(!socket->is_open())
         return 0;

   #ifdef DEBUG
   cout << "datagramme : " << datagramme << endl;
   #endif

   try
   {
      nb = socket->send_to(boost::asio::buffer(datagramme), *receiver_endpoint);
   }
   catch (std::exception& e)
   {
      std::cerr << e.what() << std::endl;
      throw;
   }

   return nb;
}


int CommunicationUDP::recevoir()
{
   size_t taille;

   if(!socket->is_open())
         return 0;

   //Fait en sorte d'être connu du serveur
   boost::array<char, 1> send_buf  = { 0 };
   try
   {
      socket->send_to(boost::asio::buffer(send_buf), *receiver_endpoint);
   }
   catch (std::exception& e)
   {
      std::cerr << e.what() << std::endl;
      throw;

   }


   boost::array<char, 128> datagramme;
   try
   {
      taille = socket->receive_from(boost::asio::buffer(datagramme), *sender_endpoint);
   }
   catch (std::exception& e)
   {
      std::cerr << e.what() << std::endl;
      throw;

   }

   #ifdef DEBUG
   std::cout << "taille : " << taille << endl;
   std::cout << "datagramme : " << datagramme.data() << endl;
   //std::cout.write(trame_recue.data(), taille);
   #endif

   return 0;
}


int CommunicationUDP::fermer()
{
   socket->close();

   #ifdef DEBUG
   std::cout << "close\n";
   #endif

   return 0;
}

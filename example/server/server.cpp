#include "SocketComm.h"
#include <chrono>
#include <thread>

struct Server
{
    Server()
        : pServer(nullptr)
        {
            SocketComm::Initialize();

            pServer = SocketComm::CreateServer();
            std::puts("Server started.");
        }

    ~Server()
        {
            SocketComm::ReleaseNode( pServer );
            std::puts("Server terminated.");

            SocketComm::Finalize();
        }

    static void ThreadEntry(Server* srv)
        {
            srv->Lisen();
        }

    void Lisen()
        {
            using namespace std::chrono_literals;

            while ( pServer )
            {
                TNMessagePtr pMsg = pServer->PopReceivedText();
                if ( pMsg != nullptr )
                {
                    std::printf("Server got message from client #%d. : %s", pMsg->ID, pMsg->Text);
                    if ( !std::strcmp(pMsg->Text, "bye\n") )
                    {
                        pServer->SendText( "bye\n", 0 );
                        break;
                    }

                    pServer->DeleteReceivedText( pMsg );
                }
                std::this_thread::sleep_for(100ms);
            }
        }

    SocketComm* pServer;
};

int main( int argc, char** argv )
{
    Server srv;
    std::thread th(Server::ThreadEntry, &srv);
    th.join();

    return 0;
}

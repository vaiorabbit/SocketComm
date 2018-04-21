#include "SocketComm.h"

int main( int argc, char** argv )
{
    SocketComm::Initialize();

    SocketComm* pServer = SocketComm::CreateServer();
    std::puts("Server started.");

    while ( pServer )
    {
        TNMessagePtr pMsg = pServer->PopReceivedText();
        if ( pMsg != NULL )
        {
            std::printf("Server got message from client #%d. : %s", pMsg->ID, pMsg->Text);
            if ( !std::strcmp(pMsg->Text, "bye\n") )
            {
                pServer->SendText( "bye\n", 0 );
                break;
            }

            pServer->DeleteReceivedText( pMsg );
        }
    }

    SocketComm::ReleaseNode( pServer );
    std::puts("Server terminated.");

    SocketComm::Finalize();

    return 0;
}

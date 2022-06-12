from telnetserver import TelnetServer

server = TelnetServer()

clients = []

while True:
    server.update()

    for new_client in server.get_new_clients():
        clients.append(new_client)
        server.send_message(new_client, "added to the client list")

    for disconnected_client in server.get_disconnected_clients():
        if disconnected_client not in clients:
            continue
        clients.remove(disconnected_client)

    for sender_client, message in server.get_messages(): 
        if sender_client not in clients:
            continue
        print(f'Message coming from client #{sender_client}')
        print(message)
        print(f'Number of clients: {len(clients)}')
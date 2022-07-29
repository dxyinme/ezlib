grpcurl -import-path path/to/protoimport \
        -proto path/to/server.proto \
        -plaintext -d '{"msg": "test"}' \
        localhost:50051 my.namespace.Server/Method
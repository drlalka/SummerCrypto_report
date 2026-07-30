while (true)
{
    /* Search for a sequence of five NOP instructions */

    if (buffer[pos]     == 0x90 &&
        buffer[pos + 1] == 0x90 &&
        buffer[pos + 2] == 0x90 &&
        buffer[pos + 3] == 0x90 &&
        buffer[pos + 4] == 0x90)
        break;

    pos++;
}

/* Read the protected block identifier */

uint64_t blockId = *(uint64_t *)(buffer + pos + 10);

/* Authenticate to the Rutoken device */

rtLoginA(...);

rtLock(...);

rtSelectByPath(...);

/* Decrypt the protected code block */

DecryptBuffer(...);

/* Copy the decrypted code back into the image */

memcpy(buffer + pos + 10, decodedBuffer, decodedSize);

/* Make the target memory writable and executable */

VirtualProtect(...);

/* Patch the current process with the decrypted code */

WriteProcessMemory(...);